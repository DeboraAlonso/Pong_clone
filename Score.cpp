#include "Score.h"
#include "Config.h"
#include "Ball.h"
#include <sstream>


using namespace std;

Score::Score()
{
	setScore();

	scoreFont();

	setFont();

	setFont();

	fontSize();

	fontColor();

	scorePosition();

}

void Score::setScore()
{
	//Set the score in 0.
	point_Player = 0;

	point_IA = 0;
}

void Score::scoreFont()
{
	//Load font file.
	font.loadFromFile("Assets/neon_pixel-7.ttf");
}

void Score::setFont()
{
	//Set text font.
	text_Player.setFont(font);

	text_IA.setFont(font);
}

void Score::fontSize()
{
	//Setting font size.
	text_Player.setCharacterSize(85);

	text_IA.setCharacterSize(85);
}

void Score::fontColor()
{
	//Set font color.
	text_Player.setFillColor(Color(51, 255, 51));

	text_IA.setFillColor(Color(51, 255, 51));
}

void Score::scorePosition()
{
	//Setting font position at superior corners. 
	text_Player.setPosition(250, 5);

	text_IA.setPosition(WIDTH - 230 - text_IA.getGlobalBounds().width, 5);
}

void Score::addPointP1()
{
	point_Player ++;
}

void Score::addPointIA()
{
	point_IA ++;
}

void Score::show(RenderWindow& Wind)
{
	//Define 2 streams to convert int to string.
	stringstream IA;

	stringstream J1;

	//Obtain string results from points.
	IA << point_IA;

	J1 << point_Player;

	//Setting the string in player and IA texts.
	text_IA.setString(IA.str());

	text_Player.setString(J1.str());

	//Reset the position of the right text to maintain alignment.
	text_IA.setPosition(WIDTH - 230 - text_IA.getLocalBounds().width, 5);

	//Drawing texts.
	Wind.draw(text_Player);

	Wind.draw(text_IA);
}