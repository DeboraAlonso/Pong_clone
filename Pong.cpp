#include "Pong.h"
#include "Config.h"

Pong::Pong()
{
	Wind.create(VideoMode(WIDTH, HEIGHT, BPP), "PONG CLONE", Style::Close);

	Wind.setVerticalSyncEnabled(true);

	bckgr_tx.loadFromFile()



}