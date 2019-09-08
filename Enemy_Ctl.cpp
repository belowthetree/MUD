#include "Enemy_Ctl.h"

Enemy_Ctl::Enemy_Ctl(string name, int xp, int HP, int power, int speed, int defense, int level, int money, string des):Charactor_Ctl(Enemy, xp, 1000, level, money, HP)
{
	this->des = des;
	this->name = name;
	this->power = power;
	this->speed = speed;
	this->defense = defense;
}
