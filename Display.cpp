#pragma once
#include "Display.h"
#include<iostream>
#include<Windows.h>
#include"Place.h"

using namespace std;

void Display::Welcome()
{
	system("cls");
	cout << "·欢迎来到《沧海镖局》，本游戏中你将扮演一名镖师，护送朝廷机密信息前往京城。" << endl <<
		"·路上将会遇到各种敌人,请在消灭他们的同时于指定时间内完成任务" << endl <<
		"·以下为此次运镖路线:" << endl;
	Display::PrintMap();
}

int Display::Tour(int index, int way, Charactor_Ctl* player, Place site[], int day, int max_day)
{
	string tmp;
	int i;
	if (way < site[index].length)
	{
		if (day >= max_day)
		{
			cout << "超出时限，运镖失败！准备返回主界面！" << endl;
			Sleep(1500);
			system("cls");
			return -1;
		}
		cout << "此地剩余路程:" << site[index].length - way << ",任务剩余天数:" << max_day - day << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

void Display::PrintMap()
{
	cout << "等级/路程" << endl;
	cout << "                    ----->琅琊群山-----             -->武当山---             " << endl;
	cout << "                   /       (6/5)       \\           /     (7/4)  \\           " << endl;
	cout << "                  /                     \\         /              \\          " << endl;
	cout << "沧海镖局-->梁州城                        ->平安客栈-->燕王府------->京城      " << endl;
	cout << "  (3/1)     (4/3) \\                     /   (6/4) \\    (9/3)     / (10/1)   " << endl;
	cout << "                   \\                   /           \\            /           " << endl;
	cout << "                    -->天泉山庄-->槐都-             -->百草药谷-               " << endl;
	cout << "                         (4/3)   (5/4)                 (8/5)                  " << endl;
}

