#pragma once
#include<string>
using namespace std;
class Goods
{
public:
	int damage;
	int defense;
	int value;

	string name;

	Goods(string name);
	~Goods();
};

