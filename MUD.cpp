#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include"Goods.h"
#include"Charactor_Ctl.h"
#include"Store.h"
#include<conio.h>
#include"Display.h"
#include"Input.h"
#include"Place.h"
#include"global.h"

using namespace std;

char ins;
int index;
int way;

Charactor_Ctl * Load()
{
	// TODO
	return new Charactor_Ctl(Sword);
}

int main()
{
	// Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100
	//Charactor_Ctl player(Sword);
	// Store 传入地点等级（1 - 5）
	Display::Welcome();			// 显示欢迎界面
	Charactor_Ctl* player;		

	while (true)
	{

#pragma region 初始处理
		int tmp = Input::Welcome();			// 1.新的游戏 2.读取存档 3.退出
		if (tmp == 1)
			tmp = Input::ChooseWork();		// 1.剑客 2.游侠 3.武师
		else if (tmp == 2)
		{
			tmp = 0;
		}
		else
			break;
		system("cls");
		index = 0;
		way = 0;
#pragma endregion

#pragma region 处理选择角色
		if (tmp == 1)
			player = new Charactor_Ctl(Sword);
		else if (tmp == 2)
			player = new Charactor_Ctl(Shoot);
		else if (tmp == 3)
			player = new Charactor_Ctl(Warrior);
		else
			player = Load();
#pragma endregion

#pragma region 上路
		while (true)
		{
			if(way == 0)
				site[index].Print();
			// -1 表示失败,回到欢迎界面; 0 表示正常前进,但仍未走出当前地点; 1 表示走出当前地点
			tmp = Display::Tour(index, way, player, site, day, max_day);
			if (tmp == -1)
				continue;
			else if (tmp == 0)
			{
				// 1.整理背包 2.逗留 3.前进 4.查看自身状态 5.存储进度
				while (tmp = Input::InTour())
				{
					if (tmp == 3 || tmp == 2)
						break;
					system("cls");
					if (tmp == 1)
					{
						cout << "背包" << endl;
						player->ShowGoods();
						cout << "穿戴" << endl;
						player->ShowCarried();
					}
					else if (tmp == 4)
						player->ShowSelf();
				}
				day++;
				way++;
			}
			else if (tmp == 1)
			{
				day++;
				way = 1;
			}
		}
		cin >> tmp;
		exit(0);
#pragma endregion

	}
	return 0;
}