#include "Enemy.h"
#include <string>

Enemy::Enemy(std::string name, char tile, int level, int attack, int defense, int health, int xp) 
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;

}

//sets position of Enemy
void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//Get the position of Enemy using reference variable
void Enemy::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}
