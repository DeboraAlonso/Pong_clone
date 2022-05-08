#pragma once
#ifndef PONG_H
#define PONG_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <time.h>

#include "Ball.h"
#include "Paddle.h"
#include "Score.h"


using namespace sf;

class Pong
{
public:

	Pong();

	void gameScreen();

	void loop();

	void processEvt();

	void processMusic();

	void loadGraph();

	void draw();

	void processPaddle();

	void update();



private:

	RenderWindow Wind;

	Clock clock;

	Time time;

	Event evt;

	Texture bckgr_tx;

	Sprite background;

	Music music;

	bool isPlaying;

	Ball ball;

	Paddle pad_Player;

	Paddle pad_IA;

	Score score;

	unsigned int sleep(unsigned int seconds);

};
#endif // !PONG_H


//AGREGAR LA FUNCION DE GAMEOVER. 
