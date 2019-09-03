#include<string>
#include<vector>
#include<iostream>
#include<windows.h>
using namespace std;
int day = 0;
enum Type
{
	Defense,
	Attack,
	other
};
class Charactor;
class Enermy;
class Goods
{
public:
	string name;
	Type type;
	int hp;
	int magic;            //穿戴性物品
	int power;
	int defense;
	int speed;
	int value;
	Goods(string name, int power, int defense, int speed, int value, Type type);
	Goods(string name, int hp, int magic,int value,Type type);
	bool use(Charactor &player);         //消耗性物品使用（未定）
};
class eskill
{
public:
	string name;
	int damage;
	int magic;
	int speed;					// 分别降低敌人敏捷、力量、防御
	int power;
	int defense;
	void act(Charactor &player, Enermy &enermy,int &nowspeed,int &nowpower,int &nowdefense);
	eskill(string na, int ma, int dam, int sp, int po, int de);
};
class pskill
{
public:
    string name;
    int damage;
    int speed;
    int power;
    int defense;
    pskill(string na, int dam,int sp, int po, int de);
    void act(Charactor &player, Enermy &enermy,int &nowspeed,int &nowpower,int &nowdefense);
};
enum Work
{
	Sword,
	Shoot,
	Warrior,
};
class Charactor
{
public:
	int level;
	int maxHP;
	int maxMagic;				// 分别是最大生命值、最大魔法值、等级、经验、金钱
	int mXP;
	int money;
	int HP;						// 当前生命值、当前魔法值
	int Magic;
	int XP;
	int speed;					// 分别对应敏捷、力量、防御
	int power;
	int defense;
	int maxCarried;
	void (*grown)(Charactor &player);
	vector<Goods> carried;           // 穿着的物品
	vector<Goods> bag;               // 拥有的物品
	vector<eskill> sheet;
	void Daily_Recovery();			// 每天会回复最大生命值的百分比
	bool AddGoods(Goods good);		// 给人物添加物品
	void ShowGoods();				// 显示物品
	bool DeleteGoods(int i);		// 删除物品
	int GetSpeed();					// 获取总的敏捷
	int GetPower();					// 获取总的力量
	int GetDefense();				// 获取总的防御
	bool PutOffCarried(int id);		// 脱掉装备放包里
	void AddCarried(Goods good);	// 穿上装备
	void DeleteCarried(int id);		// 扔掉装备
	void ShowCarried();				// 显示穿着的物品
	void ShowSheet();				// 显示技能
	void Showself();               //显示自身状态
	Charactor(int level = 1, int maxHP = 0, int maxMagic = 100, int money = 100);
	void job(Work work); //职业调整能力
};
class Enermy
{
public:
	string name;
	string plot;
	int HP;
	int level;
	int speed;					// 分别对应敏捷、力量、防御
	int power;
	int defense;
	Enermy(string name, int level, int HP, int speed, int power, int defense, string plot);
	Enermy(){}
	vector<pskill>sheet;
	void change(){}     //随即改变敌人属性（未定）
};
Goods::Goods(string name, int power, int defense, int speed, int value, Type type)
{
	this->name = name;
	this->power = power;
	this->defense = defense;
	this->speed = defense;
	this->value = value;
	this->type = type;
	hp=0;
	magic=0;
}
bool Goods::use(Charactor &player) { if (type == other)return true; }         //消耗性物品使用（未定）
void Swordgrow(Charactor &player){
    player.maxHP+=0;
	player.maxMagic+=0;
	player.speed+=0;
	player.power+=0;
	player.defense+=0;
}
void Shootgrow(Charactor &player)
{
    player.maxHP+=0;
	player.maxMagic+=0;
	player.speed+=0;
	player.power+=0;
	player.defense+=0;
}
void Warriorgrow(Charactor &player)
{
    player.maxHP+=0;
	player.maxMagic+=0;
	player.speed+=0;
	player.power+=0;
	player.defense+=0;
}
Charactor::Charactor(int level , int maxHP , int maxMagic , int money )
{
	this->level = level;
	this->maxHP = maxHP;
	HP = maxHP;
	this->maxMagic = maxMagic;
	Magic = maxMagic;
	this->money = money;
	maxCarried = 3;
	mXP = XP = 0;
	defense = 0;
	power = 0;
	speed = 0;
	grown = 0;
}
void Charactor::job(Work work) //职业调整能力
{
	if (work == Sword)
	{
		grown = &Swordgrow;
		defense = 5;
		power = 10;
		speed = 5;
	}
	else if (work == Shoot)
	{
	    grown = &Shootgrow;
		defense = 5;
		power = 5;
		speed = 10;
	}
	else if (work == Warrior)
	{
	    grown = &Warriorgrow;
		defense = 10;
		power = 5;
		speed = 5;
	}
}
// 回复 10% 的血量、魔法
void Charactor::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	Magic = Magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	Magic = Magic > maxHP ? maxHP : Magic;
}
// 添加物品
bool Charactor::AddGoods(Goods good)
{
	if (bag.size() < maxCarried)bag.push_back(good);
	else return false;
	return true;
}
// 显示物品列表
void Charactor::ShowGoods()
{
	for (int i = 0; i < bag.size(); i++)
		cout << i + 1 << ". " << bag[i].name << endl;
}
// 用于删除某个物品，成功则返回true，否则false
bool Charactor::DeleteGoods(int i)
{
	int cnt = 0;
	for (vector<Goods>::iterator it = bag.begin();it != bag.end();it++)
		if (cnt++ == i)
		{
			bag.erase(it);
			return true;
		}
	return false;
}
int Charactor::GetSpeed()
{
	int sum = this->speed;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).speed;
	}
	return sum;
}
int Charactor::GetPower()
{
	int sum = this->power;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).power;
	}
	return sum;
}
int Charactor::GetDefense()
{
	int sum = this->defense;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		sum += (*it).defense;
	}
	return sum;
}
bool Charactor::PutOffCarried(int id)
{
	if (bag.size() == maxCarried)return false;
	int cnt = 0;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		if (cnt++ == id)
		{
			bag.push_back((*it));
			carried.erase(it);
			return true;
		}
	}
}
void Charactor::AddCarried(Goods good)
{
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		if ((*it).type == good.type)
		{
			carried.erase(it);
		}
	}
	carried.push_back(good);
}
void Charactor::DeleteCarried(int id)
{
	int cnt = 0;
	for (vector<Goods>::iterator it = carried.begin(); it != carried.end(); it++)
	{
		if (cnt++ == id)
		{
			carried.erase(it);
			return;
		}
	}
}
void Charactor::ShowCarried()
{
	if (carried.size() == 0)
	{
		cout << "无物品" << endl;
		return;
	}
	cout << "名字，力量，防御，敏捷，价值" << endl;
	for (int i = 0; i < carried.size(); i++)
	{
		cout << i + 1 << ". " << carried[i].name <<","<< carried[i].power << "," <<
			carried[i].defense << "," << carried[i].speed << "," << carried[i].value << endl;
	}
}
void Charactor::ShowSheet()
{
    for (int i = 0; i < sheet.size(); i++)
	{
		cout << i + 1 << ". " << sheet[i].name << endl;
	}
}
void Charactor::Showself()
{
    cout<<"等级:"<<level<<endl;
    cout<<"体力:"<<HP<<'/'<<maxHP<<endl;
    cout<<"真气:"<<Magic<<'/'<<maxMagic<<endl;
    cout<<"金钱:"<<money<<endl;
    cout<<"力量:"<<GetPower()<<endl;
    cout<<"防御:"<<GetDefense()<<endl;
    cout<<"速度:"<<GetSpeed()<<endl;
}
Enermy::Enermy(string name, int level, int HP, int speed, int power, int defense, string plot)
{
	this->name = name;
	this->level = level;
	this->HP = HP;
	this->speed = speed;
	this->power = power;
	this->defense = defense;
	this->plot = plot;
}
eskill::eskill(string na, int ma, int dam, int sp, int po, int de)
{
    name = na;
    magic = ma;
    damage = dam;
    speed = sp;
    power = po;
    defense = de;
}
void eskill::act(Charactor &player, Enermy &enermy,int &nowspeed,int &nowpower,int &nowdefense)
{
	int harm = damage;
	enermy.HP -= harm;
	player.Magic -= magic;
	cout << "你使用了" << name << "！敌人受到了" << damage << "点伤害" << endl;
	if (speed != 0)
	{
		enermy.speed -= speed;
		cout << "敌人速度降低了" << speed << endl;
	}
	if (power != 0)
	{
		enermy.power -= power;
		cout << "敌人力量降低了" << power << endl;
	}
	if (defense != 0)
	{
		enermy.defense -= defense;
		cout << "敌人防御降低了" << defense << endl;
	}
}
pskill::pskill(string na, int dam,int sp, int po, int de)
{
    name = na;
    damage = dam;
    speed = sp;
    power = po;
    defense = de;
}
void pskill::act(Charactor &player, Enermy &enermy,int &nowspeed,int &nowpower,int &nowdefense)
{
	int harm = damage;
	player.HP -= harm;
	cout << enermy.name << "对你使用了" << name << "！你受到了" << harm << "点伤害" << endl;
    if (speed != 0)
	{
		nowspeed -= speed;
		cout << "你速度降低了" << speed << endl;
	}
	if (power != 0)
	{
		nowpower -= power;
		cout << "你力量降低了" << power << endl;
	}
	if (defense != 0)
	{
		nowdefense -= defense;
		cout << "你防御降低了" << defense << endl;
	}
}
void skillauto(Enermy &enermy, Charactor &player,int &nowspeed,int &nowpower,int &nowdefense)
{
	int i = 0;									//敌人随机使用技能（未定）
	//enermy.sheet[i].act(player, enermy,nowspeed,nowpower,nowdefense);
}
void skillchoose(Enermy& enermy, Charactor& player,int &nowspeed,int &nowpower,int &nowdefense)
{
	string tmp;
	int i, j;
	cout << "提示：玩家体力:" << player.HP << '/' << player.maxHP << ",玩家真气:" << player.Magic << '/' << player.maxMagic << ",敌人血量:" << enermy.HP << endl;
	cout << "请选择行动：1.普攻 2.使用武技 3.使用道具 ";
	cin >> tmp;
	i = tmp[0] - '0';
	while (i > 3 || i < 1)
	{
		cout << "无效命令！" << endl;
		cin >> tmp;
		i = tmp[0] - '0';
	}
	switch (i)
	{
	case 1:
		player.sheet[0].act(player, enermy,nowspeed,nowpower,nowdefense); //玩家与敌人的0号技能为普攻
		break;
	case 2:
		player.ShowSheet();
		cout << "请选择技能：";
		cin >> tmp;
		j = tmp[0] - '0';
		while (j > 4 || j < 1)
		{
			cout << "无效命令！" << endl;
			cin >> tmp;
			j = tmp[0] - '0';
		}
		player.sheet[j - 1].act(player, enermy,nowspeed,nowpower,nowdefense);
		break;
	case 3:
		player.ShowGoods();
		cout << "请选择：";
		cin >> tmp;
		j = tmp[0] - '0';
		while (j > player.bag.size() || j < 1)
		{
			cout << "无效命令！" << endl;
			cin >> tmp;
			j = tmp[0] - '0';
		}
		player.bag[j - 1].use(player);				 //消耗性物品使用（未定）
	}
}
void fight(Enermy& enermy, Charactor& player, int id)
{
    int nowspeed=player.GetSpeed();
    int nowpower=player.GetPower();
    int nowdefense=player.GetDefense();
	cout << enermy.plot << endl;
	cout << "你与" << enermy.name << "发生了战斗!" << endl;
    Sleep(3000);
    system("cls");
	while (1)
	{
		if (enermy.speed > nowspeed)
		{
			skillauto(enermy, player,nowspeed,nowpower,nowdefense);
			if (player.HP <= 0)break;
			skillchoose(enermy, player,nowspeed,nowpower,nowdefense);
			if (enermy.HP <= 0)break;
		}
		else
		{
			skillchoose(enermy, player,nowspeed,nowpower,nowdefense);
			if (enermy.HP <= 0)break;
			skillauto(enermy, player,nowspeed,nowpower,nowdefense);
			if (player.HP <= 0)break;
		}
        Sleep(3000);
		system("cls");
	}
    Sleep(3000);
    system("cls");
	if (player.HP <= 0 && id != 0 && id != 3)
	{
		cout << "你被"<<enermy.name<<"击败了！准备返回主界面！" << endl;
	}
	if (player.HP <= 0 && (id == 0 || id == 3))
	{
		cout << "切磋失败,不获得奖励！" << endl;
		player.HP = player.maxHP;
	}
	if (enermy.HP <= 0)              //玩家成长并判断等级（未定）
	{
	    cout << "你击败了"<<enermy.name<<"!获得了金币和经验" << endl;
		player.money += 0;
		player.XP += 0;
		if (player.XP >= player.mXP)
		{
			player.XP -= player.mXP;
			player.level++;
			player.grown(player);
            player.HP=player.maxHP;
            player.Magic=player.maxMagic;
			//物品获得（未定）
		}
	}
}
eskill playerplan[1]={eskill("攻击",0,10,5,0,0)};
pskill enermyplan[1]={pskill("攻击",0,0,0,0)};
class place
{
public:
	string name;
	int level;            //地点等级
	int length;           //地点长度
	string plot;          //地点介绍
	place(string a, int b, int c, string e);
	void fprint(); //打印地点介绍
};
void place::fprint()
{
	cout << plot << endl;
}
place::place(string a, int b, int c, string e)
{
	name = a;
	level = b;
	length = c;
	plot = e;
}
void mapprint()                    //显示地图
{
	cout << "等级/路程           ----->琅琊群山-----             -->武当山---             " << endl;
	cout << "                   /       (6/5)       \\           /     (7/4)  \\           " << endl;
	cout << "                  /                     \\         /              \\          " << endl;
	cout << "沧海镖局-->梁州城                        ->平安客栈-->燕王府------->京城      " << endl;
	cout << "  (3/1)     (4/3) \\                     /   (6/4) \\    (9/3)     / (10/1)   " << endl;
	cout << "                   \\                   /           \\            /           " << endl;
	cout << "                    -->天泉山庄-->槐都-             -->百草药谷-               " << endl;
	cout << "                         (4/3)   (5/4)                 (8/5)                  " << endl;
}
int nextmap[10][3] = {              //地图连接
1,0,0,
2,3,0,
5,0,0,
4,0,0,
5,0,0,
6,7,8,
9,0,0,
9,0,0,
9,0,0,
};
place site[10] = {
place("沧海镖局",0,1,"你准备从镖局出发,请准备妥当！"),
place("梁州城",0,3,"你来到了梁州城，这里是西部的商业大城，有许多商贩走卒。但最近城内潜入了一批盗贼，请小心提防。"),
place("琅琊群山",0,5,"你来到了琅琊群山，这里山脉延绵，多有劫匪和野兽出没，其中红狼帮更是一方霸主。"),
place("天泉山庄",0,3,"你来到了天泉山庄，这里是龙泉剑派的土地，此派弟子十分好战，但他们为人正直，并不会下死手。"),
place("槐都",0,4,"你来到了槐都，这里是长生教的势力范围，他们诡异莫测，需时刻警惕。"),
place("平安客栈",0,4,"你来到了平安客栈，这里是东西交通线上的歇脚处，店内鱼龙混杂，常有邪派弟子的踪影。"),
place("武当山",0,4,"你来到了武当山，这里是武当派所属。此时武当正值内乱，一伙武当叛徒逃离了宗门。"),
place("燕王府",0,3,"你来到了燕王府，这是燕王的封地。但最近燕王蠢蠢欲动，意欲谋反。"),
place("百草药谷",0,5,"你来到了百草药谷，这里有多种毒物和猛兽。传说有妖物出没。"),
place("京城",0,4,"你来到了京城，目的地就在眼前，但你觉得事情远没有那么简单......") };
Enermy enermy[20] = {   ///string name, int level, int HP, int speed, int power, int defense, string plot
Enermy("同门剑师", 1, 1, 1, 1, 1,"你闲来无事，与同门师兄切磋了起来。"),
Enermy("同门武师", 1, 1, 1, 1, 1,"你闲来无事，与同门师兄切磋了起来。"),
Enermy("强盗", 1, 1, 1, 1, 1,"一伙强盗趁着夜色打劫了你的车队，威胁你交出所有货物"),
Enermy("飞贼", 1, 1, 1, 1, 1,"几个飞贼盯上了你，你与他们开始了周旋。"),
Enermy("土匪", 1, 1, 1, 1, 1,"一队土匪拦在了你的面前，他们说，如果你跪地求饶并交出财物，就给你一种利落的死法。"),
Enermy("野狼", 1, 1, 1, 1, 1,"一群野狼似乎把你当成了食物......"),
Enermy("龙泉弟子", 1, 1, 1, 1, 1,"你偶遇龙泉弟子，对方听闻你的名字，兴奋地要与你切磋。"),
Enermy("龙泉剑客", 1, 1, 1, 1, 1,"你偶遇龙泉剑客，对方想试试你的身手。"),
Enermy("长生教长老", 1, 1, 1, 1, 1,"一名长生教长老走到了你跟前，他说想要你的心肝炼药。"),
Enermy("长生教护法", 1, 1, 1, 1, 1,"你发现了一名长生教护法跟踪你，虽然不知道他想干什么，但你决定先下手为强。"),
Enermy("邪教密探", 1, 1, 1, 1, 1,"你发现了邪教密探，所谓正邪不两立，杀！"),
Enermy("邪教头目", 1, 1, 1, 1, 1,"邪教头目袭击了客栈，不能让他们的阴谋得逞。"),
Enermy("武当弃徒", 1, 1, 1, 1, 1,"被逐出师门的武当叛徒们落草为寇，他们盯上了你。"),
Enermy("入魔弟子", 1, 1, 1, 1, 1,"多名武当叛徒包围了你，他们似乎有些不对劲......"),
Enermy("燕王叛军", 1, 1, 1, 1, 1,"燕王叛军向你发动了进攻，绝不能让朝廷机密落入他们手中。"),
Enermy("燕王叛将", 1, 1, 1, 1, 1,"燕王叛将率领人马想将你葬身于此。"),
Enermy("猛虎", 1, 1, 1, 1, 1,"突然蹿出几只斑斓白额大虫，狭路相逢勇者胜！"),
Enermy("蛇妖", 1, 1, 1, 1, 1,"蛇群从四面向你袭来，当心它们的毒牙！"),
Enermy("东厂刺客", 1, 1, 1, 1, 1,"东厂刺客从隐蔽处冒出，想取你性命！"),
Enermy("东厂首领", 1, 1, 1, 1, 1,"东厂首领堵住了去路，用高官厚禄劝你投降，但你断然拒绝。"),
};
Enermy boss[10] = {
Enermy("师傅", 1, 1, 1, 1, 1,"即将出发前，你的师傅仍放心不下你，想再教授你些武艺。"),
Enermy("盗圣", 1, 1, 1, 1, 1,"梁州城的夜色下，传闻中的盗圣拦在了出城口，他似乎对你护送的朝廷机密非常感兴趣。"),
Enermy("红狼帮帮主", 1, 1, 1, 1, 1,"远处忽然尘土飞扬，红狼帮帮主杀到你的面前，他横刀于前，要为他的手下报仇。"),
Enermy("天泉山庄庄主", 1, 1, 1, 1, 1,"你正欲离开山庄时，伴随着一阵豪爽的笑声，天泉山庄庄主轻功踱步而来，显然只有陪他打到尽心，他才会放你离开。"),
Enermy("长生教教主", 1, 1, 1, 1, 1,"长生教在城内举行了秘法，他们似乎要用活人献祭，探明真相的你决定阻止他们。"),
Enermy("客栈掌柜", 1, 1, 1, 1, 1,"没想到客栈掌柜早已被邪教掉包，你陷入了邪教的埋伏中。"),
Enermy("武当副掌门", 1, 1, 1, 1, 1,"没想到客栈天下正派的武当也已经堕落，武当的副掌门投靠了朝廷奸人，欲于此地截杀你。"),
Enermy("燕王", 1, 1, 1, 1, 1,"燕王终于撕开了他虚伪的面具，背叛了朝廷，如今你只能破釜沉舟，拼死一搏。"),
Enermy("千年树妖", 1, 1, 1, 1, 1,"大地猛地剧烈摇晃起来，黑色的藤曼从四面涌来，原来传说中的妖物真的存在......"),
Enermy("魏公公", 1, 1, 1, 1, 1,"幕后主使终于现身......原来这一路上的种种都是魏公公的阴谋，你所护送的正是他谋反乱政的证据，朝廷的危亡就系于这一战！")
};
void event(int id, Charactor& player)
{

	int type = 0;                      //事件类型
	if (id != 2 && id != 8 && type == 1);      //遇到商店（未定）
	else if (type == 2);                    //事件待定（未定）
	else if(type == 0)
	{
		int n = 1;                    //随机生成敌人数量（未定）
		Enermy number;
		int j = 2 * id;                //根据当前地图随机抽取敌人类型（未定）
		for (int i = 0;i < n;i++)
		{
			number = enermy[j];
			number.change();
			fight(number, player, id);
			if (player.HP <= 0)break;
		}
	}
}
void save() {}
void load() {}
void Interface(int id, int way, Charactor &player)                     //功能选择界面
{
	string tmp;
	int i;
	while (way < site[id].length)
	{
		if (day >= 27)
		{
			cout << "超出时限，运镖失败！准备返回主界面！" << endl;
            Sleep(3000);
            system("cls");
			break;
		}
		cout << "此地剩余路程:" << site[id].length - way << ",剩余天数:" << 27 - day << endl;
		cout << "请选择:\n1.整理背包 2.逗留 3.前进 4.查看自身状态 5.存储进度 ";
		cin >> tmp;
		i = tmp[0] - '0';
		while (i > 4 || i < 1)
		{
			cout << "无效命令！" << endl;
			cin >> tmp;
			i = tmp[0] - '0';
		}
		system("cls");
		switch (i)
		{
		case 1:
			player.ShowCarried();
			break;
		case 2:
			event(id, player);
			day++;
			break;
		case 3:
			way++;
			if (way == site[id].length)fight(boss[id], player, id);
			else event(id, player);
			day++;
			break;
		case 4:
		    player.Showself();
			break;
		case 5:
			save();
			break;
		}
        Sleep(3000);
        system("cls");
		if (player.HP <= 0)break;
	}
}
void destination(int id, Charactor &player)			//选择下一地点
{
	string tmp;
	int j = 1, q = 0;
	if (id != 9)
	{
		cout << "你准备离开" << site[id].name << "!\n" << endl;
		mapprint();
		if (nextmap[id][1] != 0)
		{
			cout << "请选择下一地点--" << endl;
			for (q=0;nextmap[id][q] != 0 && q < 3;q++) { cout << q + 1 << '.' << site[nextmap[id][q]].name << ' '; }
			cin >> tmp;
			j = tmp[0] - '0';
			while (j > q + 1 || j <1)
			{
				cout << "无效命令！" << endl;
				cin >> tmp;
				j = tmp[0] - '0';
			}
		}
		cout << "你正前往" << site[nextmap[id][j - 1]].name << '!' << endl;
		for (int i = 0;i <= 7;i++)
		{
			Sleep(500);
			cout << '>';
		}
		system("cls");
		void adventure(int id, int way, Charactor & player);
		adventure(nextmap[id][j - 1], 0, player);
	}
	if (id == 9) cout << "护镖成功！游戏胜利！" << endl;
}
void adventure(int id, int way, Charactor & player)      //开始冒险
{
	site[id].fprint();				                  //打印地点介绍
	Interface(id, way, player);                        //功能选择界面
	if (day >= 27 || player.HP <= 0)					  //死亡回归主界面
	{
		void start();
		start();
	}
	else destination(id, player);     //选择下一地点
}
void start()						 //开始界面
{
	string tmp;
	int x;
	cout << "欢迎来到《沧海镖局》，本游戏中你将扮演一名镖师，护送朝廷机密信息前往京城。\n路上将会遇到各种敌人,请在消灭他们的同时于指定时间内完成任务\n以下为此次运镖路线:" << endl;
	mapprint();
	cout << "1.新的游戏 2.读取存档 3.退出 ";
	cin >> tmp;
	x = tmp[0] - '0';
	while (x > 3 || x < 1)
	{
		cout << "无效命令！" << endl;
		cin >> tmp;
		x = tmp[0] - '0';
	}
	Charactor player(10, 10, 100, 100);   //实例化玩家
	player.sheet.push_back(playerplan[0]);
	enermy[0].sheet.push_back(enermyplan[0]);
	switch (x)
	{
	case 1:
		system("cls");
		cout << "请选择职业：1.剑客 2.游侠 3.武师 " ;
		cin >> x;
		if (x == 1)player.job(Sword);
		if (x == 2)player.job(Shoot);
		if (x == 3)player.job(Warrior);
		system("cls");
		adventure(0, 0, player);        //开始冒险
		break;
	case 2:
		system("cls");
		load();
		break;
	case 3:
		exit(0);
	}
}
int main()
{
 start();
}
