#include "Enemy_Ctl.h"

Enemy_Ctl::Enemy_Ctl(string name, int xp, int HP, int magic, int level, int money, string des):Charactor_Ctl(Enemy, xp, 1000, level, money, HP)
{
	this->des = des;
}
