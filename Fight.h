#ifndef _FIGHT_
#define _FIGHT_

#include "Charactor_Ctl.h"

class Fight {
public:
	Fight(Charactor_Ctl* player, Charactor_Ctl* enemy);
	~Fight();
	short DecideWhoAct();
	short UseWhichSkill(Charactor_Ctl* oRole);
	struct CActSlot {
		short nRoleID;
		short nSpeed;
	};
private:
	Charactor_Ctl* pPlayer;
	Charactor_Ctl* pEnemy;
	CActSlot oActSlot[];

};
#endif
