#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int day = 0;
bool dead = false;
int nextmap[10][3] = {
1,0,0,
2,3,0,
5,0,0,
4,0,0,
5,0,0,
6,7,8,
9,0,0,
9,0,0,
9,0,0,
0,0,0 };
class place
{
public:
	string name;
	int level;
	int length;
	string plot;
	place(string a, int b, int c, string e) :name(a), level(b), length(c), plot(e) {}
	void fprint() { cout << plot << endl; }
};
place site[10] = {
place("沧海镖局",3,1,"你准备从镖局出发,请准备妥当！"),
place("梁州城",4,3,"你来到了梁州城，这里是西部的商业大城，有许多商贩走卒。但最近城内潜入了一批盗贼，请小心提防。"),
place("琅琊群山",6,5,"你来到了琅琊群山，这里山脉延绵，多有劫匪和野兽出没，其中红狼帮更是一方霸主。"),
place("天泉山庄",4,3,"你来到了天泉山庄，这里是龙泉剑派的土地，此派弟子十分好战，但他们为人正直，并不会下死手。"),
place("槐都",5,4,"你来到了槐都，这里是古墓派的势力范围，他们亦正亦邪，需时刻警惕。"),
place("平安客栈",6,4,"你来到了平安客栈，这里是东西交通线上的歇脚处，店内鱼龙混杂，常有邪派弟子的踪影。"),
place("武当山",7,4,"你来到了武当山，这里是武当派所属。此时武当正值内乱，一伙武当叛徒逃离了宗门。"),
place("燕王府",9,3,"你来到了燕王府，这是燕王的封地。但最近燕王蠢蠢欲动，意欲谋反。"),
place("百草药谷",8,5,"你来到了百草药谷，这里有多种毒物和猛兽。传说有妖物出没。"),
place("京城",10,1,"你来到了京城，目的地就在眼前，但你觉得事情远没有那么简单......"),
};
//class Goods
//{
//public:
//	string name;
//	int type;
//	int power;
//	int defense;
//	int value;
//	Goods(string a):name(a){}
//};
//vector<Goods>bag;
//void bagshow()
//{
//	cout << "\t类型\t攻击\t防御\t价格" << endl;
//	for (int i = 0;i<=bag.size();i++)
//	{
//		cout << i + 1 << '.' << bag[i].name << bag[i].type << '\t' << bag[i].power<< '\t' << bag[i].defense << '\t' << '\t' << bag[i].value << '\t' << endl;
//	}
//}