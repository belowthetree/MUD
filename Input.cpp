#include "Input.h"
#include<iostream>
#include<Windows.h>

using namespace std;

void BackNum(int n)
{
	for (int i = 0; i < n; i++)
		cout << "\b";
	for (int i = 0; i < n; i++)
		cout << " ";
	for (int i = 0; i < n; i++)
		cout << "\b";
}

void BackRow(int row)
{
	while (row-- > 0)
	{
		cout << "\b\r";
		for (int i = 0; i < 100; i++)
			cout << " ";
		cout << "\r";
	}
	
}

int Input::Welcome()
{
	cout << "1.新的游戏 2.读取存档 3.退出" << endl;
	char tmp;
	int result = 0;
	while (cin >> tmp)
	{
		if (tmp == '1')
		{
			cout << "开启新游戏!" << endl;
			Sleep(1000);
			BackRow(3);
			result = 1;
		}
		else if (tmp == '2')
		{
			cout << "正在读取存档，请稍后" << endl;
			BackRow(3);
			result = 2;
		}
		else if (tmp == '3')
		{
			cout << "再见！" << endl;
			Sleep(1000);
			result = 3;
		}
		else
		{
			cout << "选项错误，请重新输入";
			Sleep(1000);
			BackRow(2);
			continue;
		}
		break;
	}

	return result;
}

int Input::InTour()
{
	char c;
	cout << "请选择:\n1.整理物品 2.逗留 3.前进 4.查看自身状态 5.存储进度 6.查看地图" << endl;
	while (cin >> c)
	{
		int tmp = c - '0';
		if (tmp > 6 || tmp < 1)
		{
			cout << "无效的选择,请重新输入" << endl;
			Sleep(1000);
			BackRow(2);
			continue;
		}

		BackRow(3);
		return tmp;
	}
	return 0;
}

int Input::InTown()
{
	cout << "请选择:\n1.整理物品 2.逗留 3.前进 4.查看自身状态 5.存储进度 6.查看地图 7.逛一下商店" << endl;
	char c;
	while (cin >> c)
	{
		int tmp = c - '0';
		if (tmp > 7 || tmp < 1)
		{
			cout << "无效的选择,请重新输入" << endl;
			Sleep(1000);
			BackRow(2);
			continue;
		}

		BackRow(3);
		return tmp;
	}
	return 0;
}

int Input::ChooseWork()
{
	int result;
	cout << "请选择职业：1.剑客 2.游侠 3.武师 " << endl;
	char c;
	while (cin >> c)
	{
		if (c == '1')
		{
			result = 1;
			cout << "恭喜你成为了一名剑客" << endl;
			Sleep(1000);
			BackRow(3);
		}
		else if (c == '2')
		{
			result = 2;
			cout << "恭喜你成为了一名游侠" << endl;
			Sleep(1000);
			BackRow(3);
		}
		else if (c == '3')
		{
			result = 3;
			cout << "恭喜你成为了一名武师" << endl;
			Sleep(1000);
			BackRow(3);
		}
		else
		{
			cout << "选择错误，请重新输入" << endl;
			Sleep(1000);
			BackRow(2);
			continue;
		}
		break;
	}
	return 0;
}

int Input::PreFight()
{
	cout << "敌人虎视眈眈，你该怎么办：" << endl
		<< "1.逃跑 2.战斗" << endl;
	char c;
	int result;
	while (cin >> c)
	{
		result = c - '0';
		if (result < 1 || result > 2)
		{
			cout << "输入错误，请重新输入" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
}

int Input::ChangeRoute(vector<string> names)
{
	for (int i = 0; i < names.size(); i++)
	{
		cout << i + 1 << "." << names[i] << " ";
	}
	cout << endl;
	char c;
	while (cin >> c)
	{
		int result = c - '0';
		if (result > names.size() || result < 0)
		{
			cout << "输入错误，请重新输入" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
}

int Input::Shopping()
{
	char c;
	cout << "请选择 1.购买物品 2.出售物品 3.取消" << endl;
	while (cin >> c)
	{
		int result = c - '0';
		if (result > 3 || result < 1)
		{
			cout << "输入错误，请重新输入" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
	return 0;
}

int Input::Fight()
{
	char c;
	int result;
	cout << "选择技能：1.普攻 2.跳斩 3.突刺 4.震撼击" << endl;
	while (cin >> c)
	{
		result = c - '0';
		if (result < 1 || result > 4)
		{
			cout << "输入错误，请重新输入" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
	return 0;
}

