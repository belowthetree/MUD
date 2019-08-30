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
	int GetLevel(int level, Charactor_Ctl & player);           //接收人物等级，决定奖励大小
	int rexp;                          //事件奖励经验
	int rgold;                         //事件奖励金币
	int equipment;                     //事件奖励装备
	short Reward(Charactor_Ctl & player);                    //固定奖励
	//short randreward();              //随机奖励 （待修复）

	vector<Charactor_Ctl> EnemyCreate(int level);

	Event(Charactor_Ctl & player, int level);
	~Event();
};