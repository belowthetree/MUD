#pragma once
#include<iostream>

using namespace std;

class Place
{
public:
	string name;
	int level;            //地点等级
	int length;           //地点长度
	string des;          //地点介绍
	Place(string name, int level, int length, string des);
	void Print(); //打印地点介绍
};

