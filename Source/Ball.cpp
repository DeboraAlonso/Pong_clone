#include "Ball.h"
#include "Config.h"

Ball::Ball() : Sprite()
{
	ballGraphics();

	setSound();

	ballOrigin();

	settingPos();

	setSpeed();

}

void Ball::ballGraphics()
{
	//Setting Ball texture.
	ball_tx.loadFromFile("Assets/ball.png");

	this->setTexture(ball_tx);
}

void Ball::setSound()
{
	//Setting sound.
	this->buffer.loadFromFile("Assets/hitball.wav");

	this->sound.setBuffer(buffer);

	this->sound.setVolume(5.f);
}

void Ball::ballOrigin()
{
	//Setting ball origin in his centre.
	this->setOrigin(this->getLocalBounds().width / 2.0f, this->getLocalBounds().height / 2.0f);
}

void Ball::settingPos()
{
	//Setting ball position.
	this->setPosition(WIDTH / 2.0f, HEIGHT / 2.0f);
}


void Ball::setSpeed()
{
	//Setting ball speed.
	this->speed.x = 300.0f;

	this->speed.y = 300.0f;

}

void Ball::update(Time& delta, FloatRect p1, FloatRect p2, Score& score)
{
	//Ball sides < > ^ v  
	float left = this->getPosition().x - this->getOrigin().x;

	float right = this->getPosition().x + this->getOrigin().x;

	float top = this->getPosition().y - this->getOrigin().y;

	float bottom = this->getPosition().y + this->getOrigin().y;

	//Check if ball hits the window walls
	if (left <= 0 && speed.x < 0)
	{
		this->speed.x *= -1;

		this->sound.play();

		score.addPointIA();

	}

	if (right >= WIDTH && speed.x > 0)
	{
		this->speed.x *= -1;

		this->sound.play();

		score.addPointP1();

	}

	if ((top <= 0 && speed.y < 0) || (bottom >= HEIGHT && speed.y > 0))
	{
		this->speed.y *= -1;

		this->sound.play();
	}

	if (this->getGlobalBounds().intersects(p1) || this->getGlobalBounds().intersects(p2))
	{
		this->speed.x *= -1.0;

		this->sound.play();
	}

	//Ball aceleration results.
	this->move(delta.asSeconds() * this->speed.x, delta.asSeconds() * this->speed.y);
}

float Ball::getSpeedX()
{
	return speed.x;
}