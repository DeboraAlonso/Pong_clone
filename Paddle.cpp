#include "Paddle.h"
#include "Config.h"
#include "Ball.h"

Paddle::Paddle() : RectangleShape()
{
	setSpeed();

	settingSize();

	settingOrigin();

	padStetic();

}

void Paddle::setSpeed()
{
	//Setting paddle velocity in component Y.
	this->speed = 300.0f;
}

void Paddle::settingSize()
{
	//Paddle size definition.
	this->setSize(Vector2f(18, 70));
}

void Paddle::settingOrigin()
{
	//Set rectagle origin.
	this->setOrigin(9, 35);
}

void Paddle::padStetic()
{
	//Fill paddle color (black).
	this->setFillColor(Color(0, 0, 0));

	//Out line paddle color (cyan).
	this->setOutlineColor(Color(51, 255, 255));

	//Line thickness.
	this->setOutlineThickness(-2.0f);
}

void Paddle::updatePlayer(Time& delta)
{
	//get paddle position in compomnent +Y / -Y.
	float top = this->getGlobalBounds().top;

	float bottom = this->getGlobalBounds().top + this->getGlobalBounds().height;

	//Paddle movements.
	//Movement limited to the edges of the window.
	if (Keyboard::isKeyPressed(Keyboard::Up) && top > 0)
	{
		this->move(0, -delta.asSeconds() * speed);
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && bottom < HEIGHT)
	{
		this->move(0, delta.asSeconds() * speed);
	}
}

void Paddle::updateIA(Time& delta, Ball& ball)
{
	//AI moves the paddle according to the ball proximy.
	if (ball.getSpeedX() >= 0 && ball.getPosition().x >= WIDTH / 2.0f)
	{
		if (this->getPosition().y < ball.getPosition().y)
		{
			this->move(0, this->speed * delta.asSeconds());
		}

		if (this->getPosition().y > ball.getPosition().y)
		{
			this->move(0, - this->speed * delta.asSeconds());
		}
	}
}