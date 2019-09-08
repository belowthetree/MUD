#include "Event.h"
#include"Charactor_Ctl.h"
#include"Display.h"
#include<algorithm>
#include<Windows.h>
#include"Input.h"
#include"Store.h"


bool Sort(Enemy_Ctl c1, Enemy_Ctl c2)
{
	return c1.GetSpeed() > c2.GetSpeed();
}

void Wait()
{
	cout << ">>>>>>����>>>>>>";
	char c;
	cin >> c;
}

// �����ж�
bool Run()
{
	if (rand() % 20 == 0)
	{
		cout << "���ܳɹ�" << endl;
		Wait();
		return true;
	}
	else
	{
		cout << "����ʧ��" << endl;
		Wait();
		return false;
	}
}

// false. ʧ�� true. ʤ��
bool Event::Fight(Charactor_Ctl* player, vector<Enemy_Ctl> enemis)
{
	int index = 0;
	int die = 0;
	sort(enemis.begin(), enemis.end(), Sort);
	while (die != enemis.size())
	{
		if (enemis[index].Die())	// �жϵ�ǰ�����Ƿ����
		{
			die++;
			index++;
			index = index >= enemis.size() ? 0 : index;
			continue;
		}
		die = 0;
		Display::Fight(player, enemis, index);
		// �ж�����
		if (enemis[index].GetSpeed() > enemis[index].GetSpeed())
		{
			cout << "�з�����" << endl;
			Wait();
			player->GetDamge(enemis[index].GetPower() * 2);
			// �ж�����Ƿ�����
			if (player->Die())
			{
				cout << "���Ѫ���ѿգ���ʧ����" << endl;
				Wait();
				enemis.clear();
				return false;
			}
			// ��������
			int result = Input::PreFight();
			if (result == 1) // �ж�����
			{
				if (Run())
					return true;
				continue;
			}
			// ����
			else
			{
				// 1.�չ� 2.��ն 3.ͻ�� 4.�𺳻�
				result = Input::Fight();
				int damage = player->Attack(result);
				enemis[index].GetDamge(damage);
				if (enemis[index].Die())
				{
					cout << "�Է�������" << endl;
					this->Reward(player, enemis[index]);
				}
				Wait();
			}
		}
		else // ����
		{
			cout << "����������" << endl;
			int result = Input::PreFight();
			// �ж�����
			if (result == 1)
			{
				if (Run())
					return true;
			}
			// �жϼ���
			else
			{
				// 1.�չ� 2.��ն 3.ͻ�� 4.�𺳻�
				result = Input::Fight();
				int damage = player->Attack(result);
				enemis[index].GetDamge(damage);
				if (enemis[index].Die())
				{
					cout << "�Է�������" << endl;
					this->Reward(player, enemis[index]);
					Wait();
					continue;
				}
			}
			cout << "�Է����㷢���˹���" << endl;
			player->GetDamge(enemis[index].GetPower() * 2);
			Wait();
			if (player->Die())
			{
				cout << "���Ѫ���ѿգ���ʧ����" << endl;
				Wait();
				enemis.clear();
				return false;
			}
		}
		index++;
		index = index >= enemis.size() ? 0 : index;
	}

	return 0;
}

void Event::Reward(Charactor_Ctl* player, Enemy_Ctl enemy)
{
	Store store(level);
	Goods tmp = store.ReturnGoods();
	cout << "������һ����Ʒ��" << endl
		<< tmp.name << " ������" << tmp.power << "������" << tmp.defense << "���ݣ�" << tmp.speed << "��ֵ��" << tmp.value << endl;

	while (player->goods.size() >= player->maxCarried)
	{
		cout << "������������������" << endl;
		player->Clean();
	}
	player->AddGoods(tmp);
	cout << "������" << enemy.money << "���" << endl;
	Sleep(500);
	cout << "������" << enemy.XP << "����" << endl;
	Sleep(500);
	player->AddXP(enemy.XP);
	player->money += enemy.money;
}

Event::Event(Charactor_Ctl * player, int level, bool bos, int index, Enemy_Ctl boss[], Enemy_Ctl enemis[])
{
	system("cls");
	this->level = level;
	int type = rand() % 3;
	if (type == 0 || bos)	// 1/3 �ļ���ս��������bossս
	{
		vector<Enemy_Ctl> enemy;
		if (bos)
		{
			enemy.push_back(boss[index]);
		}
		else
		{
			int num = rand() % 3 + 1;
			while (num-- > 0)
			{
				enemy.push_back(enemis[index*2 + rand() % 2]);
			}
		}
		cout << enemy[0].des << endl;
		Wait();
		Fight(player, enemy);
		cout << "ս������" << endl;
	}
	else
	{
		cout << "�������·�����������������ֽ���һ��" << endl;
	}
}
Event::~Event()
	{
	}
