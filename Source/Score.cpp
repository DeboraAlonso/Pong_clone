#include "Score.h"
#include "Config.h"

#include <sstream>

using namespace std;
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

	isPlaying = true;
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

	text_Win.setFont(font);

	text_Lose.setFont(font);

	text_restart.setFont(font);
}

void Score::fontSize()
{
	//Setting font size.
	text_Player.setCharacterSize(85);

	text_IA.setCharacterSize(85);

	text_Win.setCharacterSize(100);

	text_Lose.setCharacterSize(100);

	text_restart.setCharacterSize(80);
}

void Score::fontColor()
{
	//Set font color.
	text_Player.setFillColor(Color(51, 255, 51));

	text_IA.setFillColor(Color(51, 255, 51));

	text_Win.setFillColor(Color(51, 255, 51));

	text_Win.setStyle(Text::Bold);

	text_Lose.setFillColor(Color(51, 255, 51));

	text_Lose.setStyle(Text::Bold);

	text_restart.setFillColor(Color(51, 255, 51));

	text_restart.setStyle(Text::Bold);
}

void Score::scorePosition()
{
	//Setting font position at superior corners. 
	text_Player.setPosition(250, 5);

	text_IA.setPosition(WIDTH - 230 - text_IA.getGlobalBounds().width, 5);

	text_Win.setPosition(250, 150);

	text_Lose.setPosition(250, 150);

	text_restart.setPosition(80, 300);
}

void Score::addPointP1()
{
	point_Player ++;
}

void Score::addPointIA()
{
	point_IA +=5;
}

bool Score::pointCont(RenderWindow& Wind)
{
	if (point_IA >= 5 && point_Player < 3)
	{
		Wind.draw(text_Lose);

		Wind.draw(text_restart);

		isPlaying = false;
	}

	if (point_Player >= 5 && point_IA < 3)
	{
		Wind.draw(text_Win);

		Wind.draw(text_restart);

		isPlaying = false;
	}

	return isPlaying;
}

void Score::events(RenderWindow& Wind)
{
	while (Wind.pollEvent(evt))
	{

		switch (evt.key.code)
		{
		case Keyboard::Enter:

			isPlaying = true;

			break;
		}
	}
}

void Score::textContent()
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

	text_Win.setString("You win!");

	text_Lose.setString("Pc wins!");

	text_restart.setString("Press enter to play again");
}

unsigned int Score::sleep(unsigned int seconds)
{
	return 0;
}

void Score::show(RenderWindow& Wind)
{
	textContent();

	//Reset the position of the right text to maintain alignment.
	text_IA.setPosition(WIDTH - 230 - text_IA.getLocalBounds().width, 5);

	//Drawing texts.
	Wind.draw(text_Player);

	Wind.draw(text_IA);

}