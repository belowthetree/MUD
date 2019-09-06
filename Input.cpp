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
	cout << "��ѡ��:\n1.������Ʒ 2.���� 3.ǰ�� 4.�鿴����״̬ 5.�洢���� 6.�鿴��ͼ" << endl;
	while (cin >> c)
	{
		int tmp = c - '0';
		if (tmp > 6 || tmp < 1)
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
	cout << "��ѡ��:\n1.������Ʒ 2.���� 3.ǰ�� 4.�鿴����״̬ 5.�洢���� 6.�鿴��ͼ 7.��һ���̵�" << endl;
	char c;
	while (cin >> c)
	{
		int tmp = c - '0';
		if (tmp > 7 || tmp < 1)
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

int Input::PreFight()
{
	cout << "���˻������������ô�죺" << endl
		<< "1.���� 2.ս��" << endl;
	char c;
	int result;
	while (cin >> c)
	{
		result = c - '0';
		if (result < 1 || result > 2)
		{
			cout << "�����������������" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
}

int Input::ChangeRoute(vector<string> names)
{
	for (int i = 0; i < names.size(); i++)
	{
		cout << i + 1 << "." << names[i] << " ";
	}
	cout << endl;
	char c;
	while (cin >> c)
	{
		int result = c - '0';
		if (result > names.size() || result < 0)
		{
			cout << "�����������������" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
}

int Input::Shopping()
{
	char c;
	cout << "��ѡ�� 1.������Ʒ 2.������Ʒ 3.ȡ��" << endl;
	while (cin >> c)
	{
		int result = c - '0';
		if (result > 3 || result < 1)
		{
			cout << "�����������������" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
	return 0;
}

int Input::Fight()
{
	char c;
	int result;
	cout << "ѡ���ܣ�1.�չ� 2.��ն 3.ͻ�� 4.�𺳻�" << endl;
	while (cin >> c)
	{
		result = c - '0';
		if (result < 1 || result > 4)
		{
			cout << "�����������������" << endl;
			BackRow(2);
			Sleep(1000);
			continue;
		}
		return result;
	}
	return 0;
}

