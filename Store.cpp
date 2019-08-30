#include "Store.h"
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void Store::ShowGoods()
{
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << ". " << goods[i].name << " ������" << goods[i].power << "������" << goods[i].defense << "���ݣ�" << goods[i].speed << "��ֵ��" << goods[i].value << endl;
}

Goods Store::BuyGoods(int id)
{
	int cnt = 1;
	if (id <= 0 || id > goods.size())
	{
		cout << "��������ȷ�ı��" << endl;
		return Goods(Attack, "����Ʒ", 0, 0, 0, 0);
	}
	for (vector<Goods>::iterator it = goods.begin(); it != goods.end(); it++)
	{
		if (cnt++ == id)
		{
			//Goods tmp((*it).type, (*it).name, (*it).power, (*it).defense, (*it).speed, (*it).value);
			Goods tmp = *it;
			goods.erase(it);
			return tmp;
		}
	}
}

bool Store::SellGoods(Charactor_Ctl& player, int id)
{
	int cnt = 0;
	if (id <= 0 || id > player.goods.size())
	{
		cout << "��������ȷ�ı��" << endl;
		return false;
	}
	for (vector<Goods>::iterator i = player.goods.begin(); i != player.goods.end(); i++)
	{
		if (id == cnt++)
		{
			player.money += player.goods[id].value / 2;
			player.goods.erase(i);
			return true;
		}
	}
}

// ����ص�ĵȼ������ݵȼ����г�ʼ��
Store::Store(int level)
{
	ifstream in("save/AllGoods.txt", ios::in);
	string tmp;
	vector<string> vt;
	while (getline(in, tmp))	// ���࣬���֣����������������ݣ���ֵ
	{
		for (int i = 0; i < 5; i++)						// ÿ����������ţ��ֱ�װ��vt��
		{
			int idx = tmp.find(",");
			vt.push_back(tmp.substr(0, idx));
			tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
		}
		vt.push_back(tmp);
		if (atoi(vt[5].c_str()) > level * level * 4)	// �˴�ֻѡȡ�ȼ�С�ڵ��ڵ�ǰ�ص�ȼ�����Ʒ
		{
			vt.clear();
			continue;
		}
		Type type;
		if (vt[0] == "Attack")
			type = Attack;
		else if (vt[0] == "Defense")
			type = Defense;
		else if (vt[0] == "Shoes")
			type = Shoes;
		else
			type = Cloth;
		Goods g(type, vt[1], atoi(vt[2].c_str()), atoi(vt[3].c_str()), atoi(vt[4].c_str()), atoi(vt[5].c_str()));
		goods.push_back(g);
		vt.clear();
	}
	// �̵���Ʒ������20����
	int n = goods.size();
	int t = n - 20;
	for (int i = 0; i < t; i++)
	{
		vector<Goods>::iterator it = goods.begin();
		srand((unsigned)time(0));
		int cnt = rand() % (n - i);	// ���һ�����꣬���� it ��λ��Ų�������괦
		while (cnt-- > 0)	
			it++;
		goods.erase(it);
	}
	
	in.close();
}
