#pragma once
#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <time.h>

using namespace sf;


class Score
{
public:

	Score();

	void show(RenderWindow& Wind);

	bool pointCont(RenderWindow& Wind);

	void addPointP1();

	void addPointIA();

	void setScore();

	void scoreFont();

	void setFont();

	void fontSize();

	void fontColor();

	void scorePosition();

	void textContent();

	void events(RenderWindow& Wind);


private:

	Font font;

	Text text_Player;

	Text text_IA;

	Text text_Win;

	Text text_Lose;

	Text text_restart;

	Event evt;

	bool isPlaying;

	unsigned int point_Player;

	unsigned int point_IA;

	unsigned int sleep(unsigned int seconds);

};
#endif // !SCORE_H
