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
place("�׺��ھ�",3,1,"��׼�����ھֳ���,��׼���׵���"),
place("���ݳ�",4,3,"�����������ݳǣ���������������ҵ��ǣ�������̷����䡣���������Ǳ����һ����������С�������"),
place("����Ⱥɽ",6,5,"������������Ⱥɽ������ɽ�����࣬���нٷ˺�Ұ�޳�û�����к��ǰ����һ��������"),
place("��Ȫɽׯ",4,3,"����������Ȫɽׯ����������Ȫ���ɵ����أ����ɵ���ʮ�ֺ�ս��������Ϊ����ֱ�������������֡�"),
place("����",5,4,"�������˻����������ǹ�Ĺ�ɵ�������Χ������������а����ʱ�̾��衣"),
place("ƽ����ջ",6,4,"��������ƽ����ջ�������Ƕ�����ͨ���ϵ�Ъ�Ŵ��������������ӣ�����а�ɵ��ӵ���Ӱ��"),
place("�䵱ɽ",7,4,"���������䵱ɽ���������䵱����������ʱ�䵱��ֵ���ң�һ���䵱��ͽ���������š�"),
place("������",9,3,"�������������������������ķ�ء������������������������ı����"),
place("�ٲ�ҩ��",8,5,"�������˰ٲ�ҩ�ȣ������ж��ֶ�������ޡ���˵�������û��"),
place("����",10,1,"�������˾��ǣ�Ŀ�ĵؾ�����ǰ�������������Զû����ô��......"),
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
//	cout << "\t����\t����\t����\t�۸�" << endl;
//	for (int i = 0;i<=bag.size();i++)
//	{
//		cout << i + 1 << '.' << bag[i].name << bag[i].type << '\t' << bag[i].power<< '\t' << bag[i].defense << '\t' << '\t' << bag[i].value << '\t' << endl;
//	}
//}