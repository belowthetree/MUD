#include "Charactor_Ctl.h"



bool Charactor_Ctl::GetDamge(int damage)
{
	HP -= damage;
	if (HP > 0)
		return true;
	else
		return false;
}

void Charactor_Ctl::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	magic = magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	magic = magic > maxHP ? maxHP : magic;
}

Charactor_Ctl::Charactor_Ctl()
{
	maxHP = 100;
	maxMagic = 100;
}


Charactor_Ctl::~Charactor_Ctl()
{
}
