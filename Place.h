#pragma once
#include<iostream>

using namespace std;

class Place
{
public:
	string name;
	int level;            //�ص�ȼ�
	int length;           //�ص㳤��
	string des;          //�ص����
	Place(string name, int level, int length, string des);
	void Print(); //��ӡ�ص����
};

