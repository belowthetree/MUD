#include "Charactor_Ctl.h"
#include"Store.h"

Skill Skills[] = {
	Skill("普攻", 0, 0, 0, 0),
	Skill("烈火刀", 5, 1, 2, 20),
	Skill("暗影突击", 1, 1, 5, 20),
	Skill("盾击", 2, 0, 5, 20)
};


// 死亡
bool Charactor_Ctl::Die()
{
	if (HP <= 0)
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

// 展示状态
void Charactor_Ctl::ShowSelf()
{
	cout
		<< "生命值：" << HP << "/" << maxHP << endl
		<< "精力值：" << magic << "/" << maxMagic << endl
		<< "初始力量：" << power << endl
		<< "初始防御：" << defense << endl
		<< "初始敏捷：" << speed << endl
		<< "总力量：" << Charactor_Ctl::GetPower() << endl
		<< "总防御：" << Charactor_Ctl::GetDefense() << endl
		<< "总敏捷：" << Charactor_Ctl::GetSpeed() << endl;
}

// 攻击
int Charactor_Ctl::Attack(int id)
{
	if (id == 1)
		cout << "你使用了普通攻击" << endl;
	else
	{
		cout << "你使用了" << skills[id].name << endl;
		magic -= skills[id].cost;
	}
	switch (work)
	{
	case Sword:
		return skills[id].power + this->GetPower();
	case Shoot:
		return skills[id].speed + this->GetPower();
	case Warrior:
		return skills[id].defense + this->GetPower();
	default:
		break;
	}
	return 0;
}

// 整理物品、装备
void Charactor_Ctl::Clean()
{
	char c;
	cout << "背包：" << endl;
	this->ShowGoods();
	cout << "装备" << endl;
	this->ShowCarried();
	cout << "1.扔掉装备 2.扔掉物品 3.装备物品 4.卸下装备 5.退出" << endl;

	while (cin >> c)
	{
		system("cls");
		int t;
		if (c == '1')
		{
			ShowCarried();
			cin >> t;
			DeleteCarried(t);
		}
		else if (c == '2')
		{
			cout << "0. 取消" << endl;
			ShowGoods();
			do
			{
				cin >> t;
				if (t == 0)
					break;
			} while (!DeleteGoods(t));
		}
		else if (c == '3')
		{
			cout << "0. 取消" << endl;
			ShowGoods();
			do
			{
				cin >> t;
				if (t == 0)
					break;
				if (t<1 || t>goods.size())
				{
					cout << "输入错误" << endl;
					continue;
				}
			} while (!AddCarried(goods[t - 1]));
			DeleteGoods(t);
		}
		else if (c == '4')
		{
			cout << "0. 取消" << endl;
			ShowCarried();
			cin >> t;
			if (t == 0)
				break;
			if (t<1 || t>goods.size())
			{
				cout << "输入错误" << endl;
				continue;
			}
			if (AddGoods(carried[t - 1]))
				DeleteCarried(t);
			else
			{
				cout << "无法把装备放进背包里" << endl;
				continue;
			}
		}
		else if (c == '5')
			return;
		else
		{
			cout << "输入错误" << endl;
			continue;
		}
		break;
	}
}

// 受伤
void Charactor_Ctl::GetDamge(int damage)
{
	damage -= defense;
	damage = damage > 0 ? damage : 0;
	cout << name << "受到" << damage << "点伤害" << endl;
	HP -= damage;
}

// 回复 10% 的血量、魔法
void Charactor_Ctl::Daily_Recovery()
{
	cout << "经过一天的休整，你的生命和精力恢复了一些" << endl;
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
	for (int i = 0; i < 4; i++)
		skills.push_back(Skills[i]);
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
