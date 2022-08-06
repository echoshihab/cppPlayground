#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

class Level
{
public: 
	Level();
	void load(std::string fileName, Player &player, std::vector<Enemy> &enemies);
	void print();

	void movePlayer(char input, Player &player);

	//getters
	char getTile(int x, int y);

	//setters
	void setTile(int x, int y, char tile);

private:
	void processPlayerMove(Player& player, int targetX, int targetY);
	
private:
	std::vector<std::string> _levelData;
};

