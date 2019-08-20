#include "Fight.h"
#include <assert.h>

Fight::Fight(Charactor_Ctl* player, Charactor_Ctl* enemy) {
	assert(player);
	assert(enemy);

	pPlayer = player;
	pEnemy = enemy;

	oActSlot[0].nRoleID = pPlayer->ID;
	oActSlot[0].nSpeed = pPlayer->Speed;
	oActSlot[1].nRoleID = pEnemy->ID;
	oActSlot[1].nSpeed = pEnemy->Speed;
}

short Fight::DecideWhoAct() {
	if (oActSlot[0].nSpeed >= oActSlot[1].nSpeed) {
		oActSlot[1].nSpeed += pEnemy->Speed;
		return oActSlot[0].nRoleID;
	}
	else {
		oActSlot[0].nSpeed += pPlayer->Speed;
		return oActSlot[1].nRoleID;
	}
}//敏捷低的角色在进行完谁先攻击判定后再将敏捷翻倍，所以下一击一定是原来敏捷低的角色的攻击 

short Fight::UseWhichSkill(Charactor_Ctl* oRole) {
	short nSelectedSkill = -1;
	short nSkillPower = oRole->Power;
	//short i;
	return 0;

	/*
	 if( oRole->nSkillNum )
	 {
	 for( i = 0; i< oRole->nSkillNum; ++i )
	 {
	 if (nSkillPower < (oRole->nAttack + oRole))
	 }
	 }
	 */
}