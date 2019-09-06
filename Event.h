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

	bool Fight(Charactor_Ctl * player, vector<Enemy_Ctl> enemis);	// 战斗事件
	void Reward(Charactor_Ctl* player, Enemy_Ctl enemy);		// 打死一个敌人后进行奖励
	
	Event(Charactor_Ctl * player, int level, bool bos, int index, Enemy_Ctl boss[], Enemy_Ctl enemis[]);
	~Event();
};