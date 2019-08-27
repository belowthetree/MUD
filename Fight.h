#ifndef _FIGHT_
#define _FIGHT_

#include "Charactor_Ctl.h"
#include<vector>
#include<string>

using namespace std;

class Fight {
public:

	Fight(Charactor_Ctl player, vector<Charactor_Ctl>Enemy ,int n);
	~Fight(){
	}

	short Battle(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n);
	short Damage1(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n);
	short Damage2(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n);
	short DecideWhoAct(int n);
	bool IfUseSkill(Charactor_Ctl oRole);
	struct CActSlot {
		string nRoleID;
		short nSpeed;
	};

private:
	Charactor_Ctl pPlayer;
	vector<Charactor_Ctl> pEnemy;
	int N;
	CActSlot oActSlot[];

};
#endif
