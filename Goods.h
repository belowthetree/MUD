#pragma once
#include<string>
using namespace std;

enum Type
{
	Defense,
	Attack
};
class Goods
{
public:
	Type type;
	int power;
	int defense;
	int speed;
	int value;

	string name;

	Goods(string name, int power, int defense, int speed, int value);
	~Goods();
};

