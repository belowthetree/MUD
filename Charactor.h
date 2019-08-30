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
	int maxMagic;				// �ֱ����������ֵ�����ħ��ֵ���ȼ������顢���顢��Ǯ
	int level;
	int XP;
	int money;
	int maxCarried;
	int HP;
	int magic;					// ��ǰ����ֵ����ǰħ��ֵ
	int speed;					// �ֱ��Ӧ���ݡ�����������
	int power;
	int defense;
	vector<Goods> carried;     // ���ŵ���Ʒ
	vector<Goods> bag;	   // ӵ�е���Ʒ
	void Daily_Recovery();			// ÿ���ظ��������ֵ�İٷֱ�
	bool AddGoods(Goods good);		// �����������Ʒ
	void ShowGoods();				// ��ʾ��Ʒ
	bool DeleteGoods(int i);		// ɾ����Ʒ
	int GetSpeed();					// ��ȡ�ܵ�����
	int GetPower();					// ��ȡ�ܵ�����
	int GetDefense();				// ��ȡ�ܵķ���
	bool AddCarried(Goods good);	// ����װ��
	void DeleteCarried(int id);		// �ӵ�װ��
	bool PutOffCarried(int id);		// �ѵ�װ���Ű���
	void ShowCarried();				// ��ʾ���ŵ���Ʒ
	Charactor(Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100);
	~Charactor() {}
};
// �ظ� 10% ��Ѫ����ħ��
void Charactor::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	magic = magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	magic = magic > maxHP ? maxHP : magic;
}
// �����Ʒ
bool Charactor::AddGoods(Goods good)
{
	if (bag.size() < maxCarried)bag.push_back(good);
	else return false;
	return true;
}
// ��ʾ��Ʒ�б�
void Charactor::ShowGoods()
{
	for (int i = 0; i < bag.size(); i++)
	cout << i + 1 << ". " << bag[i].name << endl;
}
// ����ɾ��ĳ����Ʒ���ɹ��򷵻�true������false
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
// �趨��ʼֵ
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

