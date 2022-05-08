#include "Pong.h"
#include "Config.h"
#include "Ball.h"

Pong::Pong()
{
	gameScreen();

	isPlaying = true;

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

	score.pointCont(Wind);

	Wind.display();

	score.events(Wind);
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
	while (Wind.isOpen())
	{
		while (score.pointCont(Wind))
		{
			time = clock.restart();

			Wind.clear();

			processEvt();

			update();

			draw();
		}
	}

}

void Pong::processEvt()
{
	while (Wind.pollEvent(evt))
	{

		switch (evt.key.code)
		{
		
		case Event::Closed:

			exit(1);

			break;

		case Keyboard::Escape:
		
			exit(1);

			break;
		}

	}

}

