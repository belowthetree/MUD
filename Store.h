#pragma once
#include"Goods.h"
#include<vector>
#include"Charactor_Ctl.h"

using namespace std;

class Store
{
public:
	vector<Goods> goods;

	void ShowGoods();							// ��ʾ��Ʒ��Ϣ
	Goods BuyGoods(int id);						// ������Ʒ��ţ�������Ʒ
	bool SellGoods(Charactor_Ctl & player, int id);// �������ʵ������Ʒ��Ž��г���

	// ����ص�ĵȼ������ݵȼ����г�ʼ��
	Store(int level);
};

