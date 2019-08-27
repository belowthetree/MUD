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
	int maxCarried;

#pragma region 属性
	int HP;
	int magic;					// 当前生命值、当前魔法值
	int speed;					// 分别对应敏捷、力量、防御
	int power;
	int defense;
#pragma endregion
	
	// 穿着的物品
	vector<Goods> carried;
	// 拥有的物品
	vector<Goods> goods;
	
	void GetDamge(int damage);		// 接收一个伤害数值，返回false表示死亡，否则返回true
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
	bool Die();						// 判断是否死亡

	Charactor_Ctl(Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100);
	~Charactor_Ctl();
};

