#pragma once
#include<iostream>
#include<time.h>
#include <stdlib.h>
#include "Charactor_Ctl.h"
#include "Goods.h"
#include "Fight.h"
using namespace std;

class Event {
public:
	int GetLevel(int level, Charactor_Ctl & player);           //��������ȼ�������������С
	int rexp;                          //�¼���������
	int rgold;                         //�¼��������
	int equipment;                     //�¼�����װ��
	short Reward(Charactor_Ctl & player);                    //�̶�����
	//short randreward();              //������� �����޸���

	vector<Charactor_Ctl> EnemyCreate(int level);

	Event(Charactor_Ctl & player, int level);
	~Event();
};