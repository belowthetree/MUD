#include "Charactor_Ctl.h"

// 受伤，返回true表示死亡
bool Charactor_Ctl::GetDamge(int damage)
{
	HP -= damage;
	if (HP > 0)
		return true;
	else
		return false;
}

// 每天回复一定的血量
void Charactor_Ctl::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	magic = magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	magic = magic > maxHP ? maxHP : magic;
}

// 添加物品
void Charactor_Ctl::AddGoods(Goods good)
{
	goods.push_back(good);
}

// 显示物品列表
void Charactor_Ctl::ShowGoods()
{
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << "、" << goods[i].name << endl;
}

// 用于删除某个物品，成功则返回true，否则false
bool Charactor_Ctl::DeleteGoods(string name)
{
	for(vector<Goods>::iterator it = goods.begin();it != goods.end();it++)
		if ((*it).name == name)
		{
			goods.erase(it);
			return true;
		}
	return false;
}

// 设定初始值
Charactor_Ctl::Charactor_Ctl(Work work, int xp, int mMagic, int level, int money, int mHP)
{
	if (work == Sword)
	{
		defense = 5;
		power = 10;
		speed = 5;
	}
	else if (work == Shoot)
	{
		defense = 5;
		power = 5;
		speed = 10;
	}
	else if (work == Warrior)
	{
		defense = 10;
		power = 5;
		speed = 5;
	}
	else if (work == Enemy)
	{
		defense = 5;
		power = 5;
		speed = 5;
	}

	maxMagic = magic = mMagic;
	maxHP = HP = mHP;
	XP = xp;
	this->level = level;
	this->money = money;
}


Charactor_Ctl::~Charactor_Ctl()
{
}
