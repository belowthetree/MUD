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
	int maxMagic;				// �ֱ����������ֵ�����ħ��ֵ���ȼ������顢���顢��Ǯ
	int level;
	int XP;
	int money;

#pragma region ����
	int HP;
	int magic;					// ��ǰ����ֵ����ǰħ��ֵ
	int speed;					// �ֱ��Ӧ���ݡ�����������
	int power;
	int defense;
#pragma endregion
	
	vector<Goods> goods;
	
	bool GetDamge(int damage);		// ����һ���˺���ֵ������false��ʾ���������򷵻�true
	void Daily_Recovery();			// ÿ���ظ��������ֵ�İٷֱ�
	void AddGoods(Goods good);		// �����������Ʒ
	void ShowGoods();				// ��ʾ��Ʒ
	bool DeleteGoods(string name);	// ɾ����Ʒ


	Charactor_Ctl(Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100);
	~Charactor_Ctl();
};

