#include "Charactor_Ctl.h"

// ����
bool Charactor_Ctl::Die()
{
	if (HP < 0)
		return true;
	else
		return false;
}
// ���ˣ�����false��ʾ����
bool Charactor_Ctl::GetDamge(int damage)
{
	HP -= damage;
}

// �ظ� 10% ��Ѫ����ħ��
void Charactor_Ctl::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	magic = magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	magic = magic > maxHP ? maxHP : magic;
}

// �����Ʒ
bool Charactor_Ctl::AddGoods(Goods good)
{
	if (goods.size() < maxCarried)
		goods.push_back(good);
	else
		return false;
	return true;
}

// ��ʾ��Ʒ�б�
void Charactor_Ctl::ShowGoods()
{
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << ". " << goods[i].name << endl;
}

// ����ɾ��ĳ����Ʒ���ɹ��򷵻�true������false
bool Charactor_Ctl::DeleteGoods(int i)
{
	int cnt = 0;
	for(vector<Goods>::iterator it = goods.begin();it != goods.end();it++)
		if (cnt++ == i)
		{
			goods.erase(it);
			return true;
		}
	return false;
}

int Charactor_Ctl::GetSpeed()
{
	int sum = this->speed;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).speed;
	}
	return sum;
}

int Charactor_Ctl::GetPower()
{
	int sum = this->power;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).power;
	}
	return sum;
}

int Charactor_Ctl::GetDefense()
{
	int sum = this->defense;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).defense;
	}
	return sum;
}

bool Charactor_Ctl::AddCarried(Goods good)
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

void Charactor_Ctl::DeleteCarried(int id)
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

bool Charactor_Ctl::PutOffCarried(int id)
{
	if(goods.size() == maxCarried)
		return false;
	
	int cnt = 0;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		if (cnt++ == id)
		{
			goods.push_back((*it));
			carried.erase(it);
			return true;
		}
	}
}

void Charactor_Ctl::ShowCarried()
{
	for (int i = 0; i < carried.size(); i++)
	{
		cout << i + 1 << ". " << carried[i].name << endl;
	}
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
	maxCarried = 10;
}


Charactor_Ctl::~Charactor_Ctl()
{
	carried.clear();
	goods.clear();
}
