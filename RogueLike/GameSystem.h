#pragma once
#include "Player.h"
#include "Level.h"
#include "Enemy.h";
#include <string>;

class GameSystem
{
public:
	GameSystem(std::string levelFile);

	void playGame();
	void playerMove();

private:
	std::string _name;
	char tile;
	Player _player;
	Level _level;
	std::vector<Enemy> _enemies;
};


