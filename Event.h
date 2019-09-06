#pragma once
#include<iostream>
#include<time.h>
#include <stdlib.h>
#include "Charactor_Ctl.h"
#include "Goods.h"
#include<vector>
#include"Enemy_Ctl.h"

using namespace std;

class Event {
public:
	int level;

	bool Fight(Charactor_Ctl * player, vector<Enemy_Ctl> enemis);	// ս���¼�
	void Reward(Charactor_Ctl* player, Enemy_Ctl enemy);		// ����һ�����˺���н���
	
	Event(Charactor_Ctl * player, int level, bool bos, int index, Enemy_Ctl boss[], Enemy_Ctl enemis[]);
	~Event();
};