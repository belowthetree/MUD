#pragma once
#include"Charactor_Ctl.h"
#include"Place.h"

class Display
{
public:
	static void PrintMap();			// ��ӡ��ͼ
	static void Welcome();			// ��ӭ����
	static int Tour(int index, int way, Charactor_Ctl* player, Place site[], int day, int max_day);				// ��;��
};

