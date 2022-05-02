#pragma once
#ifndef PONG_H
#define PONG_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Pong
{
public:

	Pong();

	void run();

private:

	RenderWindow Wind;

	Clock clock;

	Time time;

	Texture bckgr_tx;

	Sprite background;

	Music music;


};
#endif // !PONG_H
