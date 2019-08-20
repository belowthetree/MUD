#include "Charactor_Ctl.h"

// ���ˣ�����true��ʾ����
bool Charactor_Ctl::GetDamge(int damage)
{
	HP -= damage;
	if (HP > 0)
		return true;
	else
		return false;
}

// ÿ��ظ�һ����Ѫ��
void Charactor_Ctl::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	magic = magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	magic = magic > maxHP ? maxHP : magic;
}

// �����Ʒ
void Charactor_Ctl::AddGoods(Goods good)
{
	goods.push_back(good);
}

// ��ʾ��Ʒ�б�
void Charactor_Ctl::ShowGoods()
{
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << "��" << goods[i].name << endl;
}

// ����ɾ��ĳ����Ʒ���ɹ��򷵻�true������false
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

// �趨��ʼֵ
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
