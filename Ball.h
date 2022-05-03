#pragma once

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Ball: public Sprite
{
public:

	Ball();

	void update(Time& delta);

	float getSpeedX() const;


private:

	Texture ball_tx;

	Vector2f speed;

	SoundBuffer buffer;

	Sound sound;


};

#endif // !BALL_H
