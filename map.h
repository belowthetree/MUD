#pragma once
#include<iostream>
#include<windows.h>
#include<string.h>
#include"global.h"

using namespace std;

// 打印地图
void mapprint()
{
	cout << "等级/路程           ----->琅琊群山-----             -->武当山---             " << endl;
	cout << "                   /       (6/5)       \\           /     (7/4)  \\           " << endl;
	cout << "                  /                     \\         /              \\          " << endl;
	cout << "沧海镖局-->梁州城                        ->平安客栈-->燕王府------->京城      " << endl;
	cout << "  (3/1)     (4/3) \\                     /   (6/4) \\    (9/3)     / (10/1)   " << endl;
	cout << "                   \\                   /           \\            /           " << endl;
	cout << "                    -->天泉山庄-->槐都-             -->百草药谷-               "<< endl;
	cout << "                         (4/3)   (5/4)                 (8/5)                  " << endl;
}
// 保存
void save() {}
// 加载
void load() {}
void adventure(int a, int b)
{
	string tmp;
	int way = b;
	int i = 0, j = 1, q = 0;
	site[a].fprint();
	while (way < site[a].length)
	{
		if (day >= 24)
		{ 
			cout << "超出时限，运镖失败！准备返回主界面！" << endl;
			Sleep(1500);
			dead = true;
			system("cls");
			return;
		}
		cout << "此地剩余路程:" << site[a].length - way << ",剩余天数:" << 24 - day << endl;
		cout << "请选择:\n1.整理背包 2.逗留 3.前进 4.存储进度 ";
		cin >> tmp;
		i = tmp[0] - '0';
		while (i > 4 || i < 1)
		{
			cout << "无效命令！" << endl;
			cin >> tmp;
			i = tmp[0] - '0';
		}
		switch (i)
		{
		case 1:
			break;
		case 2:
			day++;
			break;
		case 3:
			day++;
			way++;
			break;
		case 4:
			save();
			break;
		}
		Sleep(500);
		system("cls");
	}
	if (a != 9)
	{
		cout << "你准备离开" << site[a].name << "!\n" << endl;
		mapprint();
		if (nextmap[a][1] != 0)
		{
			cout << "请选择下一地点--" << endl;
			for (q = 0;nextmap[a][q] != 0 && q < 3;q++) { cout << q + 1 << '.' << site[nextmap[a][q]].name << ' '; }
			cin >> tmp;
			j = tmp[0] - '0';
			while (j >= q + 1 || j <= 1) 
			{ 
				cout << "无效命令！" << endl;
				cin >> tmp;
				j = tmp[0] - '0';
			}
		}
		cout << "你正前往" << site[nextmap[a][j - 1]].name << '!' << endl;
		for (i = 0;i <= 7;i++)
		{
			Sleep(500);
			cout << '>';
		}
		system("cls");
		adventure(nextmap[a][j - 1], 0);
	}
	if (a == 9) cout << "护镖成功！游戏胜利！" << endl;
}
void start()
{
	string tmp;
	int x;
	cout << "欢迎来到《沧海镖局》，本游戏中你将扮演一名镖师，护送朝廷机密物件前往京城。\n路上将会遇到各种敌人,请在消灭他们的同时于指定时间内完成任务\n以下为此次运镖路线:" << endl;
	mapprint();
	cout << "1.新的游戏 2.读取存档 3.退出 ";
	cin >> tmp;
	x = tmp[0] - '0';
	while (x > 3 || x < 1) 
	{
		cout << "无效命令！" << endl;
		cin >> tmp;
		x = tmp[0] - '0';
	}
	switch (x)
	{
	case 1:
		system("cls");
		adventure(0, 0);
        if(dead)start();
		break;
	case 2:
		system("cls");
		load();
		break;
	case 3:
		exit(0);
	}
}