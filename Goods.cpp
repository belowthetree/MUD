#include "Goods.h"

Goods::Goods(Type type, string name, int power, int defense, int speed, int value)
{
	this->type = type;
	this->name = name;
	this->power = power;
	this->defense = defense;
	this->speed = defense;
	this->value = value;
}


Goods::~Goods()
{

}
