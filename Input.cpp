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
	cout << "请选择:\n1.查看背包 2.逗留 3.前进 4.查看自身状态 5.存储进度 " << endl;
	while (cin >> c)
	{
		int tmp = c - '0';
		if (tmp > 5 || tmp < 1)
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
