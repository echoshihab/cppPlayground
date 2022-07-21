#pragma once
#include "Player.h"
#include "Level.h"
#include <string>;

class GameSystem
{
public:
	GameSystem(std::string levelFile);

	void playGame();

private:
	Player _player;
	Level _level;
};


