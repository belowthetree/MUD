#include "Charactor_Ctl.h"
#include"Store.h"

// 死亡
bool Charactor_Ctl::Die()
{
	if (HP < 0)
		return true;
	else
		return false;
}
// 经验上升
void Charactor_Ctl::AddXP(int xp)
{
	this->XP += xp;
	if (XP > level * 20)
	{
		power += work == Sword ? level * 2 : level * 1;	// 相对应的职业增加更多
		speed += work == Shoot ? level * 2 : level * 1;
		defense += work == Warrior ? level * 2 : level * 1;
		level++;
		XP = 0;
	}
}
// 受伤，返回false表示死亡
void Charactor_Ctl::GetDamge(int damage)
{
	HP -= damage;
}

// 回复 10% 的血量、魔法
void Charactor_Ctl::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	magic = magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	magic = magic > maxHP ? maxHP : magic;
}

// 添加物品
bool Charactor_Ctl::AddGoods(Goods good)
{
	if (goods.size() < maxCarried)
		goods.push_back(good);
	else
		return false;
	return true;
}

// 显示物品列表
void Charactor_Ctl::ShowGoods()
{
	if (goods.size() == 0)
	{
		cout << "无物品" << endl;
		return;
	}
	cout << "名字，力量，防御，敏捷，价值" << endl;
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << ". " << goods[i].name << "," << goods[i].power << "," <<
		goods[i].defense << "," << goods[i].speed << "," << goods[i].value << endl;
}

// 用于删除某个物品，成功则返回true，否则false
bool Charactor_Ctl::DeleteGoods(int i)
{
	int cnt = 1;
	if (i < 1 || i > goods.size())
	{
		cout << "请输入正确的编号" << endl;
		return false;
	}
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
	int cnt = 1;
	if (id < 1 || id > goods.size())
	{
		cout << "请输入正确的编号" << endl;
		return;
	}
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
	if (carried.size() == 0)
	{
		cout << "无物品" << endl;
		return;
	}
	cout << "名字，力量，防御，敏捷，价值" << endl;
	for (int i = 0; i < carried.size(); i++)
	{
		cout << i + 1 << ". " << carried[i].name <<","<< carried[i].power << "," <<
			carried[i].defense << "," << carried[i].speed << "," << carried[i].value << endl;
	}
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
	maxCarried = 10;
	this->work = work;
	//ID = 0;
}

Charactor_Ctl::Charactor_Ctl(int level)
{
	this->work = Enemy;
	this->level = level;
	this->XP = level * 4;
	this->money = 10 + level * level * 4 + rand() % (level * 4);
	this->HP = this->maxHP = 50 + level * level * 2;
	this->power = level * 3 + rand() % level;
	this->defense = level * 3 + rand() % level;
	this->speed = level * 3 + rand() % level;
	if (rand() % 5 == 0)
	{
		Store store(level);
		this->carried.push_back(store.BuyGoods(rand() % store.goods.size() + 1));
	}
	magic = 0;
	maxCarried = 1;
	maxMagic = 0;
}

Charactor_Ctl::~Charactor_Ctl()
{
	carried.clear();
	goods.clear();
}
