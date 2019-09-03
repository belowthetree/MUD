#include "Input.h"
#include<iostream>
#include<Windows.h>

using namespace std;

void BackNum(int n)
{
	for (int i = 0; i < n; i++)
		cout << "\b";
	for (int i = 0; i < n; i++)
		cout << " ";
	for (int i = 0; i < n; i++)
		cout << "\b";
}

void BackRow(int row)
{
	while (row-- > 0)
	{
		cout << "\b\r";
		for (int i = 0; i < 100; i++)
			cout << " ";
		cout << "\r";
	}
	
}

int Input::Welcome()
{
	cout << "1.�µ���Ϸ 2.��ȡ�浵 3.�˳�" << endl;
	char tmp;
	int result = 0;
	while (cin >> tmp)
	{
		if (tmp == '1')
		{
			cout << "��������Ϸ!" << endl;
			Sleep(1000);
			BackRow(3);
			result = 1;
		}
		else if (tmp == '2')
		{
			cout << "���ڶ�ȡ�浵�����Ժ�" << endl;
			BackRow(3);
			result = 2;
		}
		else if (tmp == '3')
		{
			cout << "�ټ���" << endl;
			Sleep(1000);
			result = 3;
		}
		else
		{
			cout << "ѡ���������������";
			Sleep(1000);
			BackRow(2);
			continue;
		}
		break;
	}

	return result;
}

int Input::InTour()
{
	char c;
	cout << "��ѡ��:\n1.�鿴���� 2.���� 3.ǰ�� 4.�鿴����״̬ 5.�洢���� " << endl;
	while (cin >> c)
	{
		int tmp = c - '0';
		if (tmp > 5 || tmp < 1)
		{
			cout << "��Ч��ѡ��,����������" << endl;
			Sleep(1000);
			BackRow(2);
			continue;
		}

		BackRow(3);
		return tmp;
	}
	return 0;
}

int Input::InTown()
{
	return 0;
}

int Input::ChooseWork()
{
	int result;
	cout << "��ѡ��ְҵ��1.���� 2.���� 3.��ʦ " << endl;
	char c;
	while (cin >> c)
	{
		if (c == '1')
		{
			result = 1;
			cout << "��ϲ���Ϊ��һ������" << endl;
			Sleep(1000);
			BackRow(3);
		}
		else if (c == '2')
		{
			result = 2;
			cout << "��ϲ���Ϊ��һ������" << endl;
			Sleep(1000);
			BackRow(3);
		}
		else if (c == '3')
		{
			result = 3;
			cout << "��ϲ���Ϊ��һ����ʦ" << endl;
			Sleep(1000);
			BackRow(3);
		}
		else
		{
			cout << "ѡ���������������" << endl;
			Sleep(1000);
			BackRow(2);
			continue;
		}
		break;
	}
	return 0;
}
