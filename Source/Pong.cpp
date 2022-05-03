#include "Pong.h"
#include "Config.h"
#include "Ball.h"

Pong::Pong()
{
	gameScreen();

	gameOver = false;

	loadGraph();

	update();

	processPaddle();

	processMusic();

	loop();

}

void Pong::gameScreen()
{
	//Game window creation.
	Wind.create(VideoMode(WIDTH, HEIGHT, BPP), "PONG CLONE");

	//FPS sincronization (60).
	Wind.setVerticalSyncEnabled(true);
}

void Pong::loadGraph()
{
	//Load texture from file.
	bckgr_tx.loadFromFile("Assets/background.png");

	//Setting texture for background sprite.
	background.setTexture(bckgr_tx);
}

void Pong::draw()
{
	Wind.draw(background);

	Wind.draw(ball);

	Wind.draw(pad_Player);

	Wind.draw(pad_IA);

	score.show(Wind);

	Wind.display();
}

void Pong::processPaddle()
{
	//Setting paddles position.
	pad_Player.setPosition(40, HEIGHT / 2);

	pad_IA.setPosition(WIDTH - 40, HEIGHT/2);
}

void Pong::processMusic()
{
	//Background music
	music.openFromFile("Assets/Around_The_World-DP.ogg");

	music.setLoop(true);

	music.play();
}

void Pong::update()
{

	//Classes update.
	pad_Player.updatePlayer(time);

	pad_IA.updateIA(time, ball);

	ball.update(time, pad_Player.getGlobalBounds(), pad_IA.getGlobalBounds(), score);
}

void Pong::loop ()
{
	while (!gameOver)
	{
		time = clock.restart();

		Wind.clear();

		processEvt();

		update();

		draw();
		
	}

}

void Pong::processEvt()
{
	while (Wind.pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:

			exit(1);

			break;

		}

		if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
		{
			exit(1);
		}
	}

}

