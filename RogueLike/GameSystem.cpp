#include "GameSystem.h"
#include <iostream>
#include <conio.h>

GameSystem::GameSystem(std::string levelFileName)
{
	_player.init(1, 100, 10, 10, 0);
	_level.load(levelFileName, _player);
	_level.print();

	system("PAUSE");
}

void GameSystem::playGame()
{
	bool isDone = false;

	while (isDone != true) {
		_level.print();
		playerMove();
		

	}
}

void GameSystem::playerMove() {
	char input;
	printf("Enter a move command (w/s/a/d): ");
	input = _getch();

	_level.movePlayer(input, _player);

	
}