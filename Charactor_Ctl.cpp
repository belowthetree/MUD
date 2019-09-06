#include "Charactor_Ctl.h"
#include"Store.h"

Skill Skills[] = {
	Skill("�չ�", 0, 0, 0, 0),
	Skill("�һ�", 5, 1, 2, 20),
	Skill("��Ӱͻ��", 1, 1, 5, 20),
	Skill("�ܻ�", 2, 0, 5, 20)
};


// ����
bool Charactor_Ctl::Die()
{
	if (HP <= 0)
		return true;
	else
		return false;
}

// ��������
void Charactor_Ctl::AddXP(int xp)
{
	this->XP += xp;
	if (XP > level * 20)
	{
		power += work == Sword ? level * 2 : level * 1;	// ���Ӧ��ְҵ���Ӹ���
		speed += work == Shoot ? level * 2 : level * 1;
		defense += work == Warrior ? level * 2 : level * 1;
		level++;
		XP = 0;
	}
}

// չʾ״̬
void Charactor_Ctl::ShowSelf()
{
	cout
		<< "����ֵ��" << HP << "/" << maxHP << endl
		<< "����ֵ��" << magic << "/" << maxMagic << endl
		<< "��ʼ������" << power << endl
		<< "��ʼ������" << defense << endl
		<< "��ʼ���ݣ�" << speed << endl
		<< "��������" << Charactor_Ctl::GetPower() << endl
		<< "�ܷ�����" << Charactor_Ctl::GetDefense() << endl
		<< "�����ݣ�" << Charactor_Ctl::GetSpeed() << endl;
}

// ����
int Charactor_Ctl::Attack(int id)
{
	if (id == 1)
		cout << "��ʹ������ͨ����" << endl;
	else
	{
		cout << "��ʹ����" << skills[id].name << endl;
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

// ������Ʒ��װ��
void Charactor_Ctl::Clean()
{
	char c;
	cout << "������" << endl;
	this->ShowGoods();
	cout << "װ��" << endl;
	this->ShowCarried();
	cout << "1.�ӵ�װ�� 2.�ӵ���Ʒ 3.װ����Ʒ 4.ж��װ�� 5.�˳�" << endl;

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
			cout << "0. ȡ��" << endl;
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
			cout << "0. ȡ��" << endl;
			ShowGoods();
			do
			{
				cin >> t;
				if (t == 0)
					break;
				if (t<1 || t>goods.size())
				{
					cout << "�������" << endl;
					continue;
				}
			} while (!AddCarried(goods[t - 1]));
			DeleteGoods(t);
		}
		else if (c == '4')
		{
			cout << "0. ȡ��" << endl;
			ShowCarried();
			cin >> t;
			if (t == 0)
				break;
			if (t<1 || t>goods.size())
			{
				cout << "�������" << endl;
				continue;
			}
			if (AddGoods(carried[t - 1]))
				DeleteCarried(t);
			else
			{
				cout << "�޷���װ���Ž�������" << endl;
				continue;
			}
		}
		else if (c == '5')
			return;
		else
		{
			cout << "�������" << endl;
			continue;
		}
		break;
	}
}

// ����
void Charactor_Ctl::GetDamge(int damage)
{
	damage -= defense;
	damage = damage > 0 ? damage : 0;
	cout << name << "�ܵ�" << damage << "���˺�" << endl;
	HP -= damage;
}

// �ظ� 10% ��Ѫ����ħ��
void Charactor_Ctl::Daily_Recovery()
{
	cout << "����һ�����������������;����ָ���һЩ" << endl;
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
	if (goods.size() == 0)
	{
		cout << "����Ʒ" << endl;
		return;
	}
	cout << "���֣����������������ݣ���ֵ" << endl;
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << ". " << goods[i].name << "," << goods[i].power << "," <<
		goods[i].defense << "," << goods[i].speed << "," << goods[i].value << endl;
}

// ����ɾ��ĳ����Ʒ���ɹ��򷵻�true������false
bool Charactor_Ctl::DeleteGoods(int i)
{
	int cnt = 1;
	if (i < 1 || i > goods.size())
	{
		cout << "��������ȷ�ı��" << endl;
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
		cout << "��������ȷ�ı��" << endl;
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
		cout << "����Ʒ" << endl;
		return;
	}
	cout << "���֣����������������ݣ���ֵ" << endl;
	for (int i = 0; i < carried.size(); i++)
	{
		cout << i + 1 << ". " << carried[i].name <<","<< carried[i].power << "," <<
			carried[i].defense << "," << carried[i].speed << "," << carried[i].value << endl;
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
