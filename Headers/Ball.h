#pragma once

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Score.h"

using namespace sf;

class Ball: public Sprite
{
public:

	Ball();

	void ballGraphics();

	void setSound();

	void ballOrigin();

	void settingPos();

	void setSpeed();

	void update(Time& delta, FloatRect p1, FloatRect p2, Score& score);

	float getSpeedX();
	

private:

	Texture ball_tx;

	Vector2f speed;

	SoundBuffer buffer;

	Sound sound;

};

#endif // !BALL_H
