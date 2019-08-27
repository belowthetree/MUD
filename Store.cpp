#include "Store.h"

void Store::ShowGoods()
{
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << ". " << goods[i].name << " 力量：" << goods[i].power << "防御：" << goods[i].defense << "敏捷：" << goods[i].speed << "价值：" << goods[i].value << endl;
}

Goods Store::BuyGoods(int id)
{
	int cnt = 0;
	if (id <= 0 || id > goods.size())
	{
		cout << "请输入正确的编号" << endl;
		return Goods("空物品", 0, 0, 0, 0);
	}
	for (vector<Goods>::iterator it = goods.begin(); it != goods.end(); it++)
	{
		if (cnt++ == id)
		{
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
		return;
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
