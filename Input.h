#pragma once
#include<string>
#include<vector>

using namespace std;

class Input
{
public:
	static int Welcome();					// ��ӭ���������
	static int InTour();					// ��;�е�����
	static int InTown();					// �����е�����
	static int ChooseWork();				// ѡ��ְҵʱ������
	static int Fight();						// ս��ʱ����
	static int PreFight();					// ս��ǰ
	static int ChangeRoute(vector<string> names);				// ѡ��·��
	static int Shopping();					// ����
};

