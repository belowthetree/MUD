#pragma once
#include"Charactor_Ctl.h"
#include"Place.h"

class Display
{
public:
	static void PrintMap();			// 打印地图
	static void Welcome();			// 欢迎界面
	static int Tour(int index, int way, Charactor_Ctl* player, Place site[], int day, int max_day);				// 旅途中
};

