#pragma once
#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>


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

};
#endif // !SCORE_H
