#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball;

class Paddle: public RectangleShape
{
public:

	Paddle();

	void setSpeed();

	void settingSize();

	void settingOrigin();

	void padStetic();

	void updatePlayer(Time& delta);

	void updateIA(Time& delta, Ball& ball);

private:

	float speed;

};

#endif // !PADDLE_H