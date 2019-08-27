#include "Store.h"

void Store::ShowGoods()
{
	for (int i = 0; i < goods.size(); i++)
		cout << i + 1 << ". " << goods[i].name << " ������" << goods[i].power << "������" << goods[i].defense << "���ݣ�" << goods[i].speed << "��ֵ��" << goods[i].value << endl;
}

Goods Store::BuyGoods(int id)
{
	int cnt = 0;
	if (id <= 0 || id > goods.size())
	{
		cout << "��������ȷ�ı��" << endl;
		return Goods("����Ʒ", 0, 0, 0, 0);
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
		cout << "��������ȷ�ı��" << endl;
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
