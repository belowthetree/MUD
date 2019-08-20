#pragma once
#include<string>
using namespace std;
class Skill
{
public:
	string name;
	int damage;

	Skill();
	Skill(string name, int dam);
	~Skill();
};

