#include "Store.h"
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void Store::ShowGoods()
{
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << ". " << goods[i].name << " 力量：" << goods[i].power << "防御：" << goods[i].defense << "敏捷：" << goods[i].speed << "价值：" << goods[i].value << endl;
}

Goods Store::BuyGoods(int id)
{
	int cnt = 1;
	if (id <= 0 || id > goods.size())
	{
		cout << "请输入正确的编号" << endl;
		return Goods(Attack, "空物品", 0, 0, 0, 0);
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
		cout << "请输入正确的编号" << endl;
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

// 传入地点的等级，根据等级进行初始化
Store::Store(int level)
{
	ifstream in("save/AllGoods.txt", ios::in);
	string tmp;
	vector<string> vt;
	while (getline(in, tmp))	// 种类，名字，力量，防御，敏捷，价值
	{
		for (int i = 0; i < 5; i++)						// 每行有五个逗号，分别装入vt中
		{
			int idx = tmp.find(",");
			vt.push_back(tmp.substr(0, idx));
			tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
		}
		vt.push_back(tmp);
		if (atoi(vt[5].c_str()) > level * level * 4)	// 此处只选取等级小于等于当前地点等级的物品
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
	// 商店物品数量在20以内
	int n = goods.size();
	int t = n - 20;
	for (int i = 0; i < t; i++)
	{
		vector<Goods>::iterator it = goods.begin();
		srand((unsigned)time(0));
		int cnt = rand() % (n - i);	// 随机一个坐标，并将 it 的位置挪到该坐标处
		while (cnt-- > 0)	
			it++;
		goods.erase(it);
	}
	
	in.close();
}
