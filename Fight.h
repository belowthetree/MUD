#ifndef _FIGHT_
#define _FIGHT_

#include "Charactor_Ctl.h"
#include<vector>
using namespace std;

class Fight {
public:
	Fight(Charactor_Ctl player, vector<Charactor_Ctl>Enemy ,int n);
	~Fight(){
	}
	short Damage(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n);
	short DecideWhoAct(int n);
	short UseWhichSkill(Charactor_Ctl* oRole);
	struct CActSlot {
		short nRoleID;
		short nSpeed;
	};
private:
	Charactor_Ctl pPlayer;
	vector<Charactor_Ctl> pEnemy;
	int N;
	CActSlot oActSlot[];

};
#endif
