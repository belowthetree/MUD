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
		cout << "ս��������������" << rexp << "����," << rgold << "����ҡ�" << endl;
	}	
	return 0;
}

// �˶����岻��
/*short Event::randreward(){
	if (Charactor_Ctl().HP > 0) {
		int main(int argc, char* argv[]);
		srand((unsigned)time(nullptr)); //srand()��������һ���Ե�ǰʱ�俪ʼ���������
		int y = rand() % 100;
		if (y > 79)
			printf("�������⽱����������һ��");
	}
	return 0;
}*/

vector<Charactor_Ctl> Event::EnemyCreate(int level)
{
	vector<Charactor_Ctl> enemy;
	int num = rand() % 3 + 1;
	// Work work, int xp = 0, int mMagic = 100, int level = 1, int money = 100, int mHP = 100������������Ĭ�Ϲ��캯��
	for (int i = 0; i < num; i++)
		enemy.push_back(Charactor_Ctl(level));
	return vector<Charactor_Ctl>();
}

Event::Event(Charactor_Ctl & player, int level) {
	int main(int argc, char* argv[]);
	srand((unsigned)time(0)); //srand()��������һ���Ե�ǰʱ�俪ʼ���������
	int x = rand() % 3;
	switch (x) {
	case 0: printf("��������һ��Ұ��"); Event::Reward(player); /*Event::randreward();*/ break;
	case 1: printf("��������һ��ǿ��"); Event::Reward(player); /*Event::randreward();*/ break;
	case 2: printf("���·���"); break;

	}
}
Event::~Event()
	{
	}
