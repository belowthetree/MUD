#pragma once
#include<string>
using namespace std;

enum Type
{
	Defense,
	Attack,
	Cloth,
	Shoes,
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

	Goods(Type type, string name, int power, int defense, int speed, int value);
	~Goods();
};

