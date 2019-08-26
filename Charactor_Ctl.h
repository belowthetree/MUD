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
class Charactor_Ctl
{
public:
	int maxHP;
	int maxMagic;				// 分别是最大生命值、最大魔法值、等级、经验、经验、金钱
	int level;
	int XP;
	int money;

#pragma region 属性
	int HP;
	int magic;					// 当前生命值、当前魔法值
	int speed;					// 分别对应敏捷、力量、防御
	int power;
	int defense;
#pragma endregion
	
	vector<Goods> goods;
	
	bool GetDamge(int damage);		// 接收一个伤害数值，返回false表示死亡，否则返回true
	void Daily_Recovery();			// 每天会回复最大生命值的百分比
	void AddGoods(Goods good);		// 给人物添加物品
	void ShowGoods();				// 显示物品
	bool DeleteGoods(string name);	// 删除物品


	Charactor_Ctl(Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100);
	~Charactor_Ctl();
};

