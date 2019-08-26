#include "Fight.h"
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Skill.h"
using namespace std;

Fight::Fight(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n) {


	pPlayer = player;
	pEnemy = Enemy;
	N = n;
	sort(Enemy.begin(), Enemy.begin()+n);
	oActSlot[0].nRoleID = pPlayer.ID;
	oActSlot[0].nSpeed = pPlayer.Speed;
	for(int i=1; i<=n; i++){
		oActSlot[n].nRoleID = pEnemy[n].ID;
		oActSlot[n].nSpeed = pEnemy[n].Speed;
	}
	
}

short Fight::DecideWhoAct(int i) {
		if (oActSlot[0].nSpeed >= oActSlot[i].nSpeed) {
			oActSlot[i].nSpeed += pEnemy[i].Speed;
			return oActSlot[0].nRoleID;
		}
		else {
			oActSlot[0].nSpeed += pPlayer.Speed;
			return oActSlot[i].nRoleID;
		}
}//���ݵ͵Ľ�ɫ�ڽ�����˭�ȹ����ж����ٽ����ݷ�����������һ��һ����ԭ�����ݵ͵Ľ�ɫ�Ĺ��� 

short Fight::UseWhichSkill(Charactor_Ctl* oRole) {
	cout << "�Ƿ�ʹ�ü���\n   Y/N \n";
	char choice;
	cin >> choice;
	if (choice == 'Y')
		oRole->Power += Skill.damage;
	return 0;
	
}
short Damage(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n) {
	for (int i = 1; i <= n; i++)
		Fight::DecideWhoAct(i);
}