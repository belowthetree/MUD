#include "Fight.h"
#include "Skill.h"
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
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
			return 1;
		}
		else {
			oActSlot[0].nSpeed += pPlayer.Speed;
			return 2;
		}
}//敏捷低的角色在进行完谁先攻击判定后再将敏捷翻倍，所以下一击一定是原来敏捷低的角色的攻击 

bool IfUseSkill(Charactor_Ctl oRole) {
	cout << "是否使用技能\n   Y/N \n";
	char choice;
	cin >> choice;
	cout << endl;
	if (choice == 'Y')
		return true;
	else
		return false;
	
}
short Battle(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n) {
	int k = 0;
	for (int j = 1; j <= n; j++)
	{
		k = DecideWhoAct(int j);
		if (k == 1)
		{
			if (IfUseSkill(player))
			{ 
				player.magic -= Skill.magic;
				Enemy[j].HP = Enemy[j].HP - Damage1(player, Enemy[j], n) - Skill.damage;
				cout << Enemy[j].ID << "受到" << Damage1(player, Enemy[j], n) + Skill.damage << "点伤害";
			}
			else {
				Enemy[j].HP -= Damage1(player, Enemy[j], n);
				cout << Enemy[j].ID << "受到" << Damage1(player, Enemy[j], n) << "点伤害";
			}
		}
		else {
			player.HP -= Damage2(player, Enemy[j], n);
			cout <<"你受到" << Damage1(player, Enemy[j], n) + Skill.damage << "点伤害";
		}
	}
	
}
//攻击敌人
short Damage1(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n) {
	short nAtk = player.power;
	short nDef = Enemy[n].defense;
	if (nAtk > nDef)
		return (nAtk - nDef + rand() % 3);
	else
		return rand() % 3;
}
//被敌人攻击
short Damage2(Charactor_Ctl player, vector<Charactor_Ctl>Enemy, int n) {
	short nAtk = Enemy[n].power;
	short nDef = player.defense;
	if (nAtk > nDef)
		return (nAtk - nDef + rand() % 3);
	else
		return rand() % 3;
}