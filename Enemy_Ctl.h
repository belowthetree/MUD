#pragma once
#include "Charactor_Ctl.h"
class Enemy_Ctl :
	public Charactor_Ctl
{
public:
	string des;
	Enemy_Ctl(string name, int xp, int HP, int magic, int level, int money, string des);
};

