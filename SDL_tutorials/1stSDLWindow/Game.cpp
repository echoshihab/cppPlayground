#include "Game.h"
#include <iostream>

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Subsystem Initialized successfully.";
	}
}

void Game::handleEvents() 
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::clean()
{
}