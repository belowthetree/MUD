#include "Place.h"

Place::Place(string name, int level, int length, string des)
{
	this->name = name;
	this->level = level;
	this->length = length;
	this->des = des;
}

void Place::Print()
{
	cout << des << endl;
}
