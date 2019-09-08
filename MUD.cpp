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
#include"Event.h"
#include<Windows.h>

using namespace std;

char ins;
int index = 0;
int way = 0;
Charactor_Ctl* player;

void Save()
{
	ofstream out("save/Person.txt", ios::out);
	out << player->work << "," << player->HP << "," << player->magic << "," << player->maxHP << "," << player->maxMagic << "," << player->power << "," << player->defense
		<< "," << player->speed << "," << player->level << endl;
	out.close();
	out.open("save/Carried.txt", ios::out);
	for (int i = 0; i < player->carried.size(); i++)
		cout << player->carried[i].type <<","<< player->carried[i].name << "," << player->carried[i].power
		<< "," << player->carried[i].defense << "," << player->carried[i].speed << "," << player->carried[i].value << endl;
	out.close();
	out.open("save/MyGoods.txt", ios::out);
	for (int i = 0; i < player->goods.size(); i++)
		cout << player->goods[i].type << "," << player->goods[i].name << "," << player->goods[i].power
		<< "," << player->goods[i].defense << "," << player->goods[i].speed << "," << player->goods[i].value << endl;
	out.close();
	out.open("save/Route.txt", ios::out);
	out << index << "," << way << endl;
	out.close();
	cout << "保存完毕" << endl;
	Sleep(1000);
}

Charactor_Ctl * Load()
{
	string tmp;
	ifstream in("save/Person.txt", ios::in);
	getline(in, tmp);
#pragma region 人物
#pragma region 职业
	int idx = tmp.find(",");
	Work work;
	int t = stoi(tmp.substr(0, idx));
	if (t == 0)
		work = Sword;
	else if (t == 1)
		work = Shoot;
	else
		work = Warrior;
	Charactor_Ctl* tp = new Charactor_Ctl(work);
#pragma endregion
#pragma region 属性
	// HP
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	idx = tmp.find(",");
	tp->HP = stoi(tmp.substr(0, idx));
	// magic
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	idx = tmp.find(",");
	tp->magic = stoi(tmp.substr(0, idx));
	// maxHP
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	idx = tmp.find(",");
	tp->maxHP = stoi(tmp.substr(0, idx));
	// maxMagic
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	idx = tmp.find(",");
	tp->maxMagic = stoi(tmp.substr(0, idx));
	// power
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	idx = tmp.find(",");
	tp->power = stoi(tmp.substr(0, idx));
	// defense
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	idx = tmp.find(",");
	tp->defense = stoi(tmp.substr(0, idx));
	// speed
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	idx = tmp.find(",");
	tp->speed = stoi(tmp.substr(0, idx));
	// level
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	tp->level = stoi(tmp);
#pragma endregion
	in.close();
	in.open("save/MyGoods.txt", ios::in);
	getline(in, tmp);
#pragma region 物品
	vector<string> vt;
	while (getline(in, tmp))	// 种类，名字，力量，防御，敏捷，价值
	{
		for (int i = 0; i < 5; i++)						// 每行有五个逗号，分别装入vt中
		{
			int idx = tmp.find(",");
			vt.push_back(tmp.substr(0, idx));
			tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
		}
		vt.push_back(tmp);
		Type type;
		if (vt[0] == "Attack")
			type = Attack;
		else if (vt[0] == "Defense")
			type = Defense;
		else if (vt[0] == "Shoes")
			type = Shoes;
		else
			type = Cloth;
		Goods g(type, vt[1], atoi(vt[2].c_str()), atoi(vt[3].c_str()), atoi(vt[4].c_str()), atoi(vt[5].c_str()));
		tp->goods.push_back(g);
		vt.clear();
	}
#pragma endregion
	in.close();
	in.open("save/Carried.txt", ios::in);
#pragma region 装备
	while (getline(in, tmp))	// 种类，名字，力量，防御，敏捷，价值
	{
		for (int i = 0; i < 5; i++)						// 每行有五个逗号，分别装入vt中
		{
			int idx = tmp.find(",");
			vt.push_back(tmp.substr(0, idx));
			tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
		}
		vt.push_back(tmp);
		Type type;
		if (vt[0] == "Attack")
			type = Attack;
		else if (vt[0] == "Defense")
			type = Defense;
		else if (vt[0] == "Shoes")
			type = Shoes;
		else
			type = Cloth;
		Goods g(type, vt[1], atoi(vt[2].c_str()), atoi(vt[3].c_str()), atoi(vt[4].c_str()), atoi(vt[5].c_str()));
		tp->carried.push_back(g);
		vt.clear();
	}
#pragma endregion
	// 旅途情况
	in.close();
	in.open("save/Route.txt", ios::in);
	getline(in, tmp);
	idx = tmp.find(",");
	index = stoi(tmp.substr(0, idx));
	tmp = tmp.substr(idx + 1, tmp.size() - idx - 1);
	way = stoi(tmp);
#pragma endregion

	in.close();
	tp->name = "你";
	return tp;
}

void Shopping()
{
	Store store(site[index].level);
	int result;
	// 1.购买 2.出售 3.取消
	do
	{
		result = Input::Shopping();
		if (result == 1)
		{
			store.ShowGoods();
			int n;
			cin >> n;
			while (!player->AddGoods(store.BuyGoods(n)))
			{
				cout << "背包已满，请整理背包" << endl;
				player->Clean();
			}
			cout << "成功购买" << player->goods[player->goods.size() - 1].name << endl;
			cout << ">>>>>>>>继续>>>>>>>>" << endl;
			char a;
			cin >> a;
		}
		else if (result == 2)
		{
			cout << "出售前请先将物品放置在背包中" << endl;
			player->Clean();
			system("cls");
			cout << "选择你要出售的物品：" << endl;
			player->ShowGoods();
			int c;
			while (cin >> c)
			{
				if (c < 1 || c > player->goods.size())
				{
					cout << "输入错误" << endl;
					continue;
				}
				break;
			}
			string name = player->goods[c - 1].name;
			store.SellGoods(*player, c);
			cout << "成功卖出货物" << name << endl;
			cout << ">>>>>>>>继续>>>>>>>>" << endl;
			char a;
			cin >> a;
		}
	} while (result != 3);
}

int main()
{
	srand(unsigned(time(0)));
	START:

	Display::Welcome();			// 显示欢迎界面
	Display::PrintMap(index, site);
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
		index = 9;
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
			if (way >= 4 && index == 9)
			{
				cout << "恭喜你，任务已完成！" << endl;
				cout << ">>>>>>继续>>>>>>";
				char c;
				cin >> c;
				goto START;
			}
			if(way == 0)
				site[index].Print();
			// -1 表示失败,回到欢迎界面; 0 表示正常前进,但仍未走出当前地点; 1 表示走出当前地点
			tmp = Display::Tour(index, way, player, site, day, max_day);
			if (tmp == -1)
				continue;
			else if (tmp == 0)
			{
				// 1.整理物品 2.逗留 3.前进 4.查看自身状态 5.存储进度 6.查看地图
				
				#pragma region 野外
				if (index != 1 && index != 5 && index != 9)
					while (tmp = Input::InTour())
					{
						if (tmp == 3 || tmp == 2)
							break;
						system("cls");
						if (tmp == 1)
						{
							player->Clean();
						}
						else if (tmp == 4)
							player->ShowSelf();
						else if (tmp == 6)
							Display::PrintMap(index, site);
						else if (tmp == 5)
						{
							Save();
						}
					}
#pragma endregion

				#pragma region 城里
				else
					while (tmp = Input::InTown())
					{
						if (tmp == 3 || tmp == 2)
							break;
						system("cls");
						if (tmp == 1)
						{
							player->Clean();
						}
						else if (tmp == 4)
							player->ShowSelf();
						else if (tmp == 6)
							Display::PrintMap(index, site);
						else if (tmp == 5)
						{
							Save();
						}
						else if (tmp == 7)
							Shopping();
					}
#pragma endregion

				day++;
				if (tmp == 3)
				{
					cout << "你继续向前走" << endl;
					way++;
				}
				else
					player->Daily_Recovery();
				cout << ">>>>>>继续>>>>>>";
				char c;
				cin >> c;
				Event event(player, site[index].level, way == site[index].length, index, boss, enemy);
				if (player->Die())
				{
					cout << "你已死亡，任务失败，将返回开始界面" << endl;
					cout << ">>>>>>继续>>>>>>";
					char c;
					cin >> c;
					goto START;
				}
					
			}
			else if (tmp == 1)
			{
				vector<string> tt;
				int result;
				Display::PrintMap(index, site);
				for (int i = 0; i < 3; i++)
					if (nextmap[index][i] != 0)
						tt.push_back(site[nextmap[index][i]].name);
				result = Input::ChangeRoute(tt);
				index = nextmap[index][result - 1];
				way = 0;
			}
			system("cls");
		}
#pragma endregion

	}
	return 0;
}