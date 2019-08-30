#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include"Goods.h"
#include"Charactor_Ctl.h"
#include"Store.h"
#include<conio.h>

using namespace std;

// Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100
Charactor_Ctl player(Sword);
// 传入地点等级（1 - 5）
Store store(3);

void Instruct()
{
	char ins;
	cout << "1. 出示装备的物品；2. 出示背包物品；3. 出示商品；" <<
		"4. 买装备并装上；5. 买装备并放包里；6. 删除着装；7. 删除背包；" << endl;

	while (cin >> ins)
	{
		int tmp;
		switch (ins)
		{
		case '1':
			player.ShowCarried();
			break;
		case '2':
			player.ShowGoods();
			break;
		case '3':
			store.ShowGoods();
			break;
		case '4':
			store.ShowGoods();
			cin >> tmp;
			player.AddCarried(store.BuyGoods(tmp));
			break;
		case '5':
			store.ShowGoods();
			cin >> tmp;
			player.AddGoods(store.BuyGoods(tmp));
			break;
		case '6':
			player.ShowCarried();
			cin >> tmp;
			player.DeleteCarried(tmp);
			break;
		case '7':
			player.ShowGoods();
			cin >> tmp;
			player.DeleteGoods(tmp);
			break;
		default:
			break;
		}
	}
}

int main()
{
	Instruct();
	return 0;
}