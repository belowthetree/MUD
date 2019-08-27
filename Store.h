#pragma once
#include"Goods.h"
#include<vector>
#include"Charactor_Ctl.h"

using namespace std;

class Store
{
public:
	vector<Goods> goods;

	void ShowGoods();							// 显示物品信息
	Goods BuyGoods(int id);						// 输入物品编号，购买物品
	bool SellGoods(Charactor_Ctl & player, int id);// 传入玩家实例，物品编号进行出售
};

