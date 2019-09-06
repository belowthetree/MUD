#pragma once
#include"Charactor_Ctl.h"
#include"Place.h"
#include<vector>
#include"Enemy_Ctl.h"

class Display
{
public:
	static void PrintMap(int index, Place site[]);			// 打印地图
	static void Welcome();			// 欢迎界面
	static int Tour(int index, int way, Charactor_Ctl* player, Place site[], int day, int max_day);				// 旅途中
	static int Fight(Charactor_Ctl * player, vector<Enemy_Ctl> enemis, int index);				// 战斗界面
};

