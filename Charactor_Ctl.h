#pragma once
class Charactor_Ctl
{
public:
	int maxHP;
	int maxMagic;				// 分别是最大生命值已经最大魔法值
	int ID;
	int HP;
	int magic;					// 当前生命值、当前魔法值

	int Speed;					// 分别对应敏捷、力量、防御
	int Power;
	int Defense;
	
	bool GetDamge(int damage);	// 接收一个伤害数值，返回false表示死亡，否则返回true
	void Daily_Recovery();		// 每天会回复最大生命值的百分比
	
	Charactor_Ctl();
	~Charactor_Ctl();
};

