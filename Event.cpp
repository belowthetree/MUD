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
	cout << ">>>>>>继续>>>>>>";
	char c;
	cin >> c;
}

// 逃跑判断
bool Run()
{
	if (rand() % 20 == 0)
	{
		cout << "逃跑成功" << endl;
		Wait();
		return true;
	}
	else
	{
		cout << "逃跑失败" << endl;
		Wait();
		return false;
	}
}

// false. 失败 true. 胜利
bool Event::Fight(Charactor_Ctl* player, vector<Enemy_Ctl> enemis)
{
	int index = 0;
	int die = 0;
	sort(enemis.begin(), enemis.end(), Sort);
	while (die != enemis.size())
	{
		if (enemis[index].Die())	// 判断当前对手是否活着
		{
			die++;
			index++;
			index = index >= enemis.size() ? 0 : index;
			continue;
		}
		die = 0;
		Display::Fight(player, enemis, index);
		// 判断先手
		if (enemis[index].GetSpeed() > enemis[index].GetSpeed())
		{
			cout << "敌方先手" << endl;
			Wait();
			player->GetDamge(enemis[index].GetPower() * 2);
			// 判断玩家是否死亡
			if (player->Die())
			{
				cout << "你的血量已空，你失败了" << endl;
				Wait();
				enemis.clear();
				return false;
			}
			// 接收输入
			int result = Input::PreFight();
			if (result == 1) // 判断逃跑
			{
				if (Run())
					return true;
				continue;
			}
			// 技能
			else
			{
				// 1.普攻 2.跳斩 3.突刺 4.震撼击
				result = Input::Fight();
				int damage = player->Attack(result);
				enemis[index].GetDamge(damage);
				if (enemis[index].Die())
				{
					cout << "对方已死亡" << endl;
					this->Reward(player, enemis[index]);
				}
				Wait();
			}
		}
		else // 先手
		{
			cout << "你获得了先手" << endl;
			int result = Input::PreFight();
			// 判断逃跑
			if (result == 1)
			{
				if (Run())
					return true;
			}
			// 判断技能
			else
			{
				// 1.普攻 2.跳斩 3.突刺 4.震撼击
				result = Input::Fight();
				int damage = player->Attack(result);
				enemis[index].GetDamge(damage);
				if (enemis[index].Die())
				{
					cout << "对方已死亡" << endl;
					this->Reward(player, enemis[index]);
					Wait();
					continue;
				}
			}
			cout << "对方想你发起了攻击" << endl;
			player->GetDamge(enemis[index].GetPower() * 2);
			Wait();
			if (player->Die())
			{
				cout << "你的血量已空，你失败了" << endl;
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
	cout << "你获得了一件物品：" << endl
		<< tmp.name << " 力量：" << tmp.power << "防御：" << tmp.defense << "敏捷：" << tmp.speed << "价值：" << tmp.value << endl;

	while (player->goods.size() >= player->maxCarried)
	{
		cout << "背包已满，请整理背包" << endl;
		player->Clean();
	}
	player->AddGoods(tmp);
	cout << "你获得了" << enemy.money << "金币" << endl;
	Sleep(500);
	cout << "你获得了" << enemy.XP << "经验" << endl;
	Sleep(500);
	player->AddXP(enemy.XP);
	player->money += enemy.money;
}

Event::Event(Charactor_Ctl * player, int level, bool bos, int index, Enemy_Ctl boss[], Enemy_Ctl enemis[])
{
	system("cls");
	this->level = level;
	int type = rand() % 3;
	if (type == 0 || bos)	// 1/3 的几率战斗，除了boss战
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
		cout << "战斗结束" << endl;
	}
	else
	{
		cout << "今日无事发生，距离任务结束又近了一天" << endl;
	}
}
Event::~Event()
	{
	}
