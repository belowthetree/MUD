#pragma once
#include<vector>
#include<iostream>
#include"Goods.h"
using namespace std;
enum Work
{
	Sword,
	Shoot,
	Warrior,
	Enemy
};
class Charactor
{
public:
	int maxHP;
	int maxMagic;				// 分别是最大生命值、最大魔法值、等级、经验、经验、金钱
	int level;
	int XP;
	int money;
	int maxCarried;
	int HP;
	int magic;					// 当前生命值、当前魔法值
	int speed;					// 分别对应敏捷、力量、防御
	int power;
	int defense;
	vector<Goods> carried;     // 穿着的物品
	vector<Goods> bag;	   // 拥有的物品
	void Daily_Recovery();			// 每天会回复最大生命值的百分比
	bool AddGoods(Goods good);		// 给人物添加物品
	void ShowGoods();				// 显示物品
	bool DeleteGoods(int i);		// 删除物品
	int GetSpeed();					// 获取总的敏捷
	int GetPower();					// 获取总的力量
	int GetDefense();				// 获取总的防御
	bool AddCarried(Goods good);	// 穿上装备
	void DeleteCarried(int id);		// 扔掉装备
	bool PutOffCarried(int id);		// 脱掉装备放包里
	void ShowCarried();				// 显示穿着的物品
	Charactor(Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100);
	~Charactor() {}
};
// 回复 10% 的血量、魔法
void Charactor::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	magic = magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	magic = magic > maxHP ? maxHP : magic;
}
// 添加物品
bool Charactor::AddGoods(Goods good)
{
	if (bag.size() < maxCarried)bag.push_back(good);
	else return false;
	return true;
}
// 显示物品列表
void Charactor::ShowGoods()
{
	for (int i = 0; i < bag.size(); i++)
	cout << i + 1 << ". " << bag[i].name << endl;
}
// 用于删除某个物品，成功则返回true，否则false
bool Charactor::DeleteGoods(int i)
{
	int cnt = 0;
	for (vector<Goods>::iterator it = bag.begin();it != bag.end();it++)
		if (cnt++ == i)
		{
			bag.erase(it);
			return true;
		}
	return false;
}
int Charactor::GetSpeed()
{
	int sum = this->speed;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).speed;
	}
	return sum;
}
int Charactor::GetPower()
{
	int sum = this->power;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).power;
	}
	return sum;
}
int Charactor::GetDefense()
{
	int sum = this->defense;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).defense;
	}
	return sum;
}
bool Charactor::AddCarried(Goods good)
{
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		if ((*it).type == good.type)
		{
			return false;
		}
	}
	carried.push_back(good);
	return true;
}
void Charactor::DeleteCarried(int id)
{
	int cnt = 0;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		if (cnt++ == id)
		{
			carried.erase(it);
			return;
		}
	}
}
bool Charactor::PutOffCarried(int id)
{
	if (bag.size() == maxCarried)
		return false;

	int cnt = 0;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		if (cnt++ == id)
		{
			bag.push_back((*it));
			carried.erase(it);
			return true;
		}
	}
}
void Charactor::ShowCarried()
{
	for (int i = 0; i < carried.size(); i++)
	{
		cout << i + 1 << ". " << carried[i].name << endl;
	}
}
// 设定初始值
Charactor::Charactor(Work work, int xp, int mMagic, int level, int money, int mHP)
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
	maxCarried = 10;
}
Charactor::~Charactor()
{
	carried.clear();
	bag.clear();
}

