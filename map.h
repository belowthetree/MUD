#pragma once
#include<iostream>
#include<windows.h>
#include<string.h>
#include"global.h"

using namespace std;

// ��ӡ��ͼ
void mapprint()
{
	cout << "�ȼ�/·��           ----->����Ⱥɽ-----             -->�䵱ɽ---             " << endl;
	cout << "                   /       (6/5)       \\           /     (7/4)  \\           " << endl;
	cout << "                  /                     \\         /              \\          " << endl;
	cout << "�׺��ھ�-->���ݳ�                        ->ƽ����ջ-->������------->����      " << endl;
	cout << "  (3/1)     (4/3) \\                     /   (6/4) \\    (9/3)     / (10/1)   " << endl;
	cout << "                   \\                   /           \\            /           " << endl;
	cout << "                    -->��Ȫɽׯ-->����-             -->�ٲ�ҩ��-               "<< endl;
	cout << "                         (4/3)   (5/4)                 (8/5)                  " << endl;
}
// ����
void save() {}
// ����
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
			cout << "����ʱ�ޣ�����ʧ�ܣ�׼�����������棡" << endl;
			Sleep(1500);
			dead = true;
			system("cls");
			return;
		}
		cout << "�˵�ʣ��·��:" << site[a].length - way << ",ʣ������:" << 24 - day << endl;
		cout << "��ѡ��:\n1.������ 2.���� 3.ǰ�� 4.�洢���� ";
		cin >> tmp;
		i = tmp[0] - '0';
		while (i > 4 || i < 1)
		{
			cout << "��Ч���" << endl;
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
		cout << "��׼���뿪" << site[a].name << "!\n" << endl;
		mapprint();
		if (nextmap[a][1] != 0)
		{
			cout << "��ѡ����һ�ص�--" << endl;
			for (q = 0;nextmap[a][q] != 0 && q < 3;q++) { cout << q + 1 << '.' << site[nextmap[a][q]].name << ' '; }
			cin >> tmp;
			j = tmp[0] - '0';
			while (j >= q + 1 || j <= 1) 
			{ 
				cout << "��Ч���" << endl;
				cin >> tmp;
				j = tmp[0] - '0';
			}
		}
		cout << "����ǰ��" << site[nextmap[a][j - 1]].name << '!' << endl;
		for (i = 0;i <= 7;i++)
		{
			Sleep(500);
			cout << '>';
		}
		system("cls");
		adventure(nextmap[a][j - 1], 0);
	}
	if (a == 9) cout << "���ڳɹ�����Ϸʤ����" << endl;
}
void start()
{
	string tmp;
	int x;
	cout << "��ӭ�������׺��ھ֡�������Ϸ���㽫����һ����ʦ�����ͳ�͢�������ǰ�����ǡ�\n·�Ͻ����������ֵ���,�����������ǵ�ͬʱ��ָ��ʱ�����������\n����Ϊ�˴�����·��:" << endl;
	mapprint();
	cout << "1.�µ���Ϸ 2.��ȡ�浵 3.�˳� ";
	cin >> tmp;
	x = tmp[0] - '0';
	while (x > 3 || x < 1) 
	{
		cout << "��Ч���" << endl;
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