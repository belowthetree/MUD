#include "Event.h"
#include"Charactor_Ctl.h"

int Event::GetLevel(int level, Charactor_Ctl & player)
{
	rexp = level * 5;
	rgold = level * 5;
	player.XP += rexp;
	player.money += rgold;
	return 0;
}

short Event::Reward(Charactor_Ctl & player) {
	if (player.HP > 0){
		cout << "战斗结束，你获得了" << rexp << "经验," << rgold << "个金币。" << endl;
	}	
	return 0;
}

// 此段意义不明
/*short Event::randreward(){
	if (Charactor_Ctl().HP > 0) {
		int main(int argc, char* argv[]);
		srand((unsigned)time(nullptr)); //srand()函数产生一个以当前时间开始的随机种子
		int y = rand() % 100;
		if (y > 79)
			printf("触发额外奖励，你获得了一件");
	}
	return 0;
}*/

vector<Charactor_Ctl> Event::EnemyCreate(int level)
{
	vector<Charactor_Ctl> enemy;
	int num = rand() % 3 + 1;
	// Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100（这是人物类默认构造函数
	for (int i = 0; i < num; i++)
		enemy.push_back(Charactor_Ctl(level));
	return vector<Charactor_Ctl>();
}

Event::Event(Charactor_Ctl & player, int level) {
	int main(int argc, char* argv[]);
	srand((unsigned)time(0)); //srand()函数产生一个以当前时间开始的随机种子
	int x = rand() % 3;
	switch (x) {
	case 0: printf("你遇到了一波野怪"); Event::Reward(player); /*Event::randreward();*/ break;
	case 1: printf("你遇到了一伙强盗"); Event::Reward(player); /*Event::randreward();*/ break;
	case 2: printf("无事发生"); break;

	}
}
Event::~Event()
	{
	}
