#pragma once
#include "Display.h"
#include<iostream>
#include<Windows.h>
#include"Place.h"

using namespace std;

void Display::Welcome()
{
	system("cls");
	cout << "����ӭ�������׺��ھ֡�������Ϸ���㽫����һ����ʦ�����ͳ�͢������Ϣǰ�����ǡ�" << endl <<
		"��·�Ͻ����������ֵ���,�����������ǵ�ͬʱ��ָ��ʱ�����������" << endl <<
		"������Ϊ�˴�����·��:" << endl;
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
			cout << "����ʱ�ޣ�����ʧ�ܣ�׼�����������棡" << endl;
			Sleep(1500);
			system("cls");
			return -1;
		}
		cout << "�˵�ʣ��·��:" << site[index].length - way << ",����ʣ������:" << max_day - day << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

void Display::PrintMap()
{
	cout << "�ȼ�/·��" << endl;
	cout << "                    ----->����Ⱥɽ-----             -->�䵱ɽ---             " << endl;
	cout << "                   /       (6/5)       \\           /     (7/4)  \\           " << endl;
	cout << "                  /                     \\         /              \\          " << endl;
	cout << "�׺��ھ�-->���ݳ�                        ->ƽ����ջ-->������------->����      " << endl;
	cout << "  (3/1)     (4/3) \\                     /   (6/4) \\    (9/3)     / (10/1)   " << endl;
	cout << "                   \\                   /           \\            /           " << endl;
	cout << "                    -->��Ȫɽׯ-->����-             -->�ٲ�ҩ��-               " << endl;
	cout << "                         (4/3)   (5/4)                 (8/5)                  " << endl;
}

