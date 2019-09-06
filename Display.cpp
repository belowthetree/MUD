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
		cout << "����" << site[index].name << endl;
		cout << "�˵�ʣ��·��:" << site[index].length - way << ",����ʣ������:" << max_day - day << endl;
		return 0;
	}
	else
	{
		cout << "�㼴���뿪" << site[index].name << endl;
		cout << "������Ҫȥ�����أ�" << endl;
		return 1;
	}
}

int Display::Fight(Charactor_Ctl * player, vector<Enemy_Ctl> enemis, int index)
{
	system("cls");

	for (int i = 0; i < enemis.size(); i++)
	{
		cout << i + 1 << "." << enemis[i].name << "  ����:" << enemis[i].HP << "/" 
			<< enemis[i].maxHP << ", ����:" <<enemis[i].GetPower()
			<< ", ���ݣ�" << enemis[i].GetSpeed() << ", ����: " << enemis[i].GetDefense() << endl;
	}
	cout << "���״̬��" << endl
		<< ", ������" << player->HP
		<< ", ������" << player->magic
		<< ", ������" << player->GetPower()
		<< ", ���ݣ�" << player->GetSpeed()
		<< ", ������" << player->GetDefense() << endl;
	return 0;
}

void Display::PrintMap(int index, Place site[])
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
	cout << "�㵱ǰ��" << site[index].name << endl;
}

