#include "Level.h"
#include <fstream>
#include <iostream>
#include "Enemy.h"



Level::Level()
{

}

void Level::load(std::string fileName, Player& player)
{
	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
	std::perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}
	std::string line;

	while (std::getline(file, line)) {
		_levelData.push_back(line);
	}

	file.close();

	//Process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch (tile) {
			//player
			case '@':
				player.setPosition(j, i);
				break;
			case 'S':
				_enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 10));
				break;
			case 'g':
				_enemies.push_back(Enemy("Goblin", tile, 2, 10, 5, 35, 50));
				break;
			case 'O':
				_enemies.push_back(Enemy("Orgre", tile, 4, 20, 20, 200, 500));
				break;
			case 'D':
				_enemies.push_back(Enemy("Dragon", tile, 100, 2000, 2000, 2000, 500000));
				break;
			case 'B':
				_enemies.push_back(Enemy("Bandit", tile, 3, 15, 10, 100, 250));
				break;



			}
		}
	}
}

void Level::print()
{
	
	std::cout << std::string(100, '\n');
	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::movePlayer(char input, Player& player) {

	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char moveTile;

	switch (tolower(input)) {
	case 'w':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a':
		processPlayerMove(player, playerX -1, playerY);
		break;
	case 'd':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	}
}

char Level::getTile(int x, int y) {
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player& player, int targetX, int targetY)
{
	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	if (moveTile == '.') {
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
	}
	 else if (moveTile != '#') {
		 battleMonster(player, targetX, targetY);
	}
}

void Level::battleMonster(Player& player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	for (int i = 0; i < _enemies.size(); i++) {
		_enemies[i].getPosition(enemyX, enemyY);

		if (targetX == enemyX && targetY == enemyY) {
			//battle

			return;
					
		} 
	}
}