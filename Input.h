#pragma once
#include<string>
#include<vector>

using namespace std;

class Input
{
public:
	static int Welcome();					// 欢迎界面的输入
	static int InTour();					// 旅途中的输入
	static int InTown();					// 城镇中的输入
	static int ChooseWork();				// 选择职业时的输入
	static int Fight();						// 战斗时输入
	static int PreFight();					// 战斗前
	static int ChangeRoute(vector<string> names);				// 选择路线
	static int Shopping();					// 购物
};

