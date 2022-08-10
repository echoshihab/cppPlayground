#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

class Level
{
public: 
	Level();
	void load(std::string fileName, Player &player);
	void print();

	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);

	//getters
	char getTile(int x, int y);

	//setters
	void setTile(int x, int y, char tile);

private:
	void processPlayerMove(Player& player, int targetX, int targetY);
	void battleMonster(Player& player, int targetX, int targetY);
	
private:
	std::vector<Enemy> _enemies;
	std::vector<std::string> _levelData;

};

