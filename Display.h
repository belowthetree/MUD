#pragma once
#include"Charactor_Ctl.h"
#include"Place.h"
#include<vector>
#include"Enemy_Ctl.h"

class Display
{
public:
	static void PrintMap(int index, Place site[]);			// ��ӡ��ͼ
	static void Welcome();			// ��ӭ����
	static int Tour(int index, int way, Charactor_Ctl* player, Place site[], int day, int max_day);				// ��;��
	static int Fight(Charactor_Ctl * player, vector<Enemy_Ctl> enemis, int index);				// ս������
};

