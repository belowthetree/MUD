#pragma once
#include<vector>
#include<iostream>
#include"Goods.h"
using namespace std;
enum Work
{
	Sword,
	Shoot,
	Warrior,
	Enemy
};
class Charactor_Ctl
{
public:
	int maxHP;
	int maxMagic;				// �ֱ����������ֵ�����ħ��ֵ���ȼ������顢���顢��Ǯ
	int level;
	int XP;
	int money;
	int maxCarried;

#pragma region ����
	int HP;
	int magic;					// ��ǰ����ֵ����ǰħ��ֵ
	int speed;					// �ֱ��Ӧ���ݡ�����������
	int power;
	int defense;
#pragma endregion
	
	// ���ŵ���Ʒ
	vector<Goods> carried;
	// ӵ�е���Ʒ
	vector<Goods> goods;
	
	void GetDamge(int damage);		// ����һ���˺���ֵ������false��ʾ���������򷵻�true
	void Daily_Recovery();			// ÿ���ظ��������ֵ�İٷֱ�
	bool AddGoods(Goods good);		// �����������Ʒ
	void ShowGoods();				// ��ʾ��Ʒ
	bool DeleteGoods(int i);		// ɾ����Ʒ
	int GetSpeed();					// ��ȡ�ܵ�����
	int GetPower();					// ��ȡ�ܵ�����
	int GetDefense();				// ��ȡ�ܵķ���
	bool AddCarried(Goods good);	// ����װ��
	void DeleteCarried(int id);		// �ӵ�װ��
	bool PutOffCarried(int id);		// �ѵ�װ���Ű���
	void ShowCarried();				// ��ʾ���ŵ���Ʒ
	bool Die();						// �ж��Ƿ�����

	Charactor_Ctl(Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100);
	~Charactor_Ctl();
};

