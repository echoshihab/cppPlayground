#include "Player.h"

//Constructor, initialize position to zero

Player::Player() 
{
	_x = 0;
	_y = 0;
}

//initialize the player with properties
void Player::init(int level, int health, int attack, int defense, int experience) 
{
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience
	
}

//sets position of player
void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//Get the position of player using reference variable
void Player::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

