#include "Ball.h"
#include "Config.h"

Ball::Ball()
{
	//Setting Ball texture.
	ball_tx.loadFromFile("Assets/ball.png");

	this->setTexture(ball_tx);

	//Setting sound.
	this->buffer.loadFromFile("Assets/hitball.wav");

	this->sound.setBuffer(buffer);

	this->sound.setVolume(50);



	//Setting ball origin in his centre.
	this->setOrigin(this->getLocalBounds().width / 2.0f, this->getLocalBounds().height / 2.0f);

	//Setting ball position.
	this->setPosition(WIDTH / 2.0f, HEIGHT / 2.0f);

	//Setting ball speed.
	this->speed.x = 300.0f;

	this->speed.y = 300.0f;

}

void Ball::update(Time& delta)
{
	//Ball sides < > ^ v  
	float left = this->getPosition().x - this->getOrigin().x;

	float right = this->getPosition().x - this->getOrigin().x;

	float top = this->getPosition().y - this->getOrigin().y;

	float bottom = this->getPosition().y - this->getOrigin().y;

	//Check if ball hits the window walls
	if (left <= 0 && speed.x < 0)
	{
		this->speed.x *= -1;
		this->sound.play();
	}

	if (right >= WIDTH && speed.x > 0)
	{
		this->speed.x *= -1;
		this->sound.play();
	}

	if ((top <= 0 && speed.y < 0) || (bottom >= HEIGHT && speed.y > 0))
	{
		this->speed.y *= -1;
		this->sound.play();
	}

	//Ball aceleration results.
	this->move(delta.asSeconds() * this->speed.x, delta.asSeconds() * this->speed.y);
}

float Ball::getSpeedX() const
{
	return speed.x;
}