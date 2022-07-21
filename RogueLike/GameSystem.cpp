#include "GameSystem.h"

GameSystem::GameSystem(std::string levelFileName)
{
	_level.load(levelFileName);
	_level.print();

	system("PAUSE");
}

void GameSystem::playGame()
{

}