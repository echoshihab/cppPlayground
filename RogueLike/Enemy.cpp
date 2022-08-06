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
