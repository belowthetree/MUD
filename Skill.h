#pragma once
#include<string>
using namespace std;
class Skill
{
public:
	string name;
	int power;
	int defense;
	int speed;
	int cost;

	Skill(string name, int power, int defense, int speed, int cost);
	~Skill();
};

