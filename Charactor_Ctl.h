#pragma once
class Charactor_Ctl
{
public:
	int maxHP;
	int maxMagic;				// �ֱ����������ֵ�Ѿ����ħ��ֵ

	int HP;
	int magic;					// ��ǰ����ֵ����ǰħ��ֵ

	int speed;					// �ֱ��Ӧ���ݡ�����������
	int power;
	int defense;
	
	bool GetDamge(int damage);	// ����һ���˺���ֵ������false��ʾ���������򷵻�true
	void Daily_Recovery();		// ÿ���ظ��������ֵ�İٷֱ�
	

	Charactor_Ctl();
	~Charactor_Ctl();
};

