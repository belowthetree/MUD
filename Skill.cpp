#include "Skill.h"



Skill::Skill(string name, int power, int defense, int speed, int cost)
{
	this->name = name;
	this->power = power;
	this->speed = speed;
	this->defense = defense;
	this->cost = cost;
}

Skill::~Skill()
{
}
