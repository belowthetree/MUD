#pragma once
class Charactor_Ctl
{
public:
	int maxHP;
	int maxMagic;				// �ֱ����������ֵ�Ѿ����ħ��ֵ
	int ID;
	int HP;
	int magic;					// ��ǰ����ֵ����ǰħ��ֵ

	int Speed;					// �ֱ��Ӧ���ݡ�����������
	int Power;
	int Defense;
	
	bool GetDamge(int damage);	// ����һ���˺���ֵ������false��ʾ���������򷵻�true
	void Daily_Recovery();		// ÿ���ظ��������ֵ�İٷֱ�
	
	Charactor_Ctl();
	~Charactor_Ctl();
};

