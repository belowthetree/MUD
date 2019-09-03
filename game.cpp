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
	int magic;            //��������Ʒ
	int power;
	int defense;
	int speed;
	int value;
	Goods(string name, int power, int defense, int speed, int value, Type type);
	Goods(string name, int hp, int magic,int value,Type type);
	bool use(Charactor &player);         //��������Ʒʹ�ã�δ����
};
class eskill
{
public:
	string name;
	int damage;
	int magic;
	int speed;					// �ֱ𽵵͵������ݡ�����������
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
	int maxMagic;				// �ֱ����������ֵ�����ħ��ֵ���ȼ������顢��Ǯ
	int mXP;
	int money;
	int HP;						// ��ǰ����ֵ����ǰħ��ֵ
	int Magic;
	int XP;
	int speed;					// �ֱ��Ӧ���ݡ�����������
	int power;
	int defense;
	int maxCarried;
	void (*grown)(Charactor &player);
	vector<Goods> carried;           // ���ŵ���Ʒ
	vector<Goods> bag;               // ӵ�е���Ʒ
	vector<eskill> sheet;
	void Daily_Recovery();			// ÿ���ظ��������ֵ�İٷֱ�
	bool AddGoods(Goods good);		// �����������Ʒ
	void ShowGoods();				// ��ʾ��Ʒ
	bool DeleteGoods(int i);		// ɾ����Ʒ
	int GetSpeed();					// ��ȡ�ܵ�����
	int GetPower();					// ��ȡ�ܵ�����
	int GetDefense();				// ��ȡ�ܵķ���
	bool PutOffCarried(int id);		// �ѵ�װ���Ű���
	void AddCarried(Goods good);	// ����װ��
	void DeleteCarried(int id);		// �ӵ�װ��
	void ShowCarried();				// ��ʾ���ŵ���Ʒ
	void ShowSheet();				// ��ʾ����
	void Showself();               //��ʾ����״̬
	Charactor(int level = 1, int maxHP = 0, int maxMagic = 100, int money = 100);
	void job(Work work); //ְҵ��������
};
class Enermy
{
public:
	string name;
	string plot;
	int HP;
	int level;
	int speed;					// �ֱ��Ӧ���ݡ�����������
	int power;
	int defense;
	Enermy(string name, int level, int HP, int speed, int power, int defense, string plot);
	Enermy(){}
	vector<pskill>sheet;
	void change(){}     //�漴�ı�������ԣ�δ����
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
bool Goods::use(Charactor &player) { if (type == other)return true; }         //��������Ʒʹ�ã�δ����
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
void Charactor::job(Work work) //ְҵ��������
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
// �ظ� 10% ��Ѫ����ħ��
void Charactor::Daily_Recovery()
{
	HP = HP + maxHP / 10;
	Magic = Magic + maxMagic / 10;
	HP = HP > maxHP ? maxHP : HP;
	Magic = Magic > maxHP ? maxHP : Magic;
}
// �����Ʒ
bool Charactor::AddGoods(Goods good)
{
	if (bag.size() < maxCarried)bag.push_back(good);
	else return false;
	return true;
}
// ��ʾ��Ʒ�б�
void Charactor::ShowGoods()
{
	for (int i = 0; i < bag.size(); i++)
		cout << i + 1 << ". " << bag[i].name << endl;
}
// ����ɾ��ĳ����Ʒ���ɹ��򷵻�true������false
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
		cout << "����Ʒ" << endl;
		return;
	}
	cout << "���֣����������������ݣ���ֵ" << endl;
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
    cout<<"�ȼ�:"<<level<<endl;
    cout<<"����:"<<HP<<'/'<<maxHP<<endl;
    cout<<"����:"<<Magic<<'/'<<maxMagic<<endl;
    cout<<"��Ǯ:"<<money<<endl;
    cout<<"����:"<<GetPower()<<endl;
    cout<<"����:"<<GetDefense()<<endl;
    cout<<"�ٶ�:"<<GetSpeed()<<endl;
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
	cout << "��ʹ����" << name << "�������ܵ���" << damage << "���˺�" << endl;
	if (speed != 0)
	{
		enermy.speed -= speed;
		cout << "�����ٶȽ�����" << speed << endl;
	}
	if (power != 0)
	{
		enermy.power -= power;
		cout << "��������������" << power << endl;
	}
	if (defense != 0)
	{
		enermy.defense -= defense;
		cout << "���˷���������" << defense << endl;
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
	cout << enermy.name << "����ʹ����" << name << "�����ܵ���" << harm << "���˺�" << endl;
    if (speed != 0)
	{
		nowspeed -= speed;
		cout << "���ٶȽ�����" << speed << endl;
	}
	if (power != 0)
	{
		nowpower -= power;
		cout << "������������" << power << endl;
	}
	if (defense != 0)
	{
		nowdefense -= defense;
		cout << "�����������" << defense << endl;
	}
}
void skillauto(Enermy &enermy, Charactor &player,int &nowspeed,int &nowpower,int &nowdefense)
{
	int i = 0;									//�������ʹ�ü��ܣ�δ����
	//enermy.sheet[i].act(player, enermy,nowspeed,nowpower,nowdefense);
}
void skillchoose(Enermy& enermy, Charactor& player,int &nowspeed,int &nowpower,int &nowdefense)
{
	string tmp;
	int i, j;
	cout << "��ʾ���������:" << player.HP << '/' << player.maxHP << ",�������:" << player.Magic << '/' << player.maxMagic << ",����Ѫ��:" << enermy.HP << endl;
	cout << "��ѡ���ж���1.�չ� 2.ʹ���似 3.ʹ�õ��� ";
	cin >> tmp;
	i = tmp[0] - '0';
	while (i > 3 || i < 1)
	{
		cout << "��Ч���" << endl;
		cin >> tmp;
		i = tmp[0] - '0';
	}
	switch (i)
	{
	case 1:
		player.sheet[0].act(player, enermy,nowspeed,nowpower,nowdefense); //�������˵�0�ż���Ϊ�չ�
		break;
	case 2:
		player.ShowSheet();
		cout << "��ѡ���ܣ�";
		cin >> tmp;
		j = tmp[0] - '0';
		while (j > 4 || j < 1)
		{
			cout << "��Ч���" << endl;
			cin >> tmp;
			j = tmp[0] - '0';
		}
		player.sheet[j - 1].act(player, enermy,nowspeed,nowpower,nowdefense);
		break;
	case 3:
		player.ShowGoods();
		cout << "��ѡ��";
		cin >> tmp;
		j = tmp[0] - '0';
		while (j > player.bag.size() || j < 1)
		{
			cout << "��Ч���" << endl;
			cin >> tmp;
			j = tmp[0] - '0';
		}
		player.bag[j - 1].use(player);				 //��������Ʒʹ�ã�δ����
	}
}
void fight(Enermy& enermy, Charactor& player, int id)
{
    int nowspeed=player.GetSpeed();
    int nowpower=player.GetPower();
    int nowdefense=player.GetDefense();
	cout << enermy.plot << endl;
	cout << "����" << enermy.name << "������ս��!" << endl;
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
		cout << "�㱻"<<enermy.name<<"�����ˣ�׼�����������棡" << endl;
	}
	if (player.HP <= 0 && (id == 0 || id == 3))
	{
		cout << "�д�ʧ��,����ý�����" << endl;
		player.HP = player.maxHP;
	}
	if (enermy.HP <= 0)              //��ҳɳ����жϵȼ���δ����
	{
	    cout << "�������"<<enermy.name<<"!����˽�Һ;���" << endl;
		player.money += 0;
		player.XP += 0;
		if (player.XP >= player.mXP)
		{
			player.XP -= player.mXP;
			player.level++;
			player.grown(player);
            player.HP=player.maxHP;
            player.Magic=player.maxMagic;
			//��Ʒ��ã�δ����
		}
	}
}
eskill playerplan[1]={eskill("����",0,10,5,0,0)};
pskill enermyplan[1]={pskill("����",0,0,0,0)};
class place
{
public:
	string name;
	int level;            //�ص�ȼ�
	int length;           //�ص㳤��
	string plot;          //�ص����
	place(string a, int b, int c, string e);
	void fprint(); //��ӡ�ص����
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
void mapprint()                    //��ʾ��ͼ
{
	cout << "�ȼ�/·��           ----->����Ⱥɽ-----             -->�䵱ɽ---             " << endl;
	cout << "                   /       (6/5)       \\           /     (7/4)  \\           " << endl;
	cout << "                  /                     \\         /              \\          " << endl;
	cout << "�׺��ھ�-->���ݳ�                        ->ƽ����ջ-->������------->����      " << endl;
	cout << "  (3/1)     (4/3) \\                     /   (6/4) \\    (9/3)     / (10/1)   " << endl;
	cout << "                   \\                   /           \\            /           " << endl;
	cout << "                    -->��Ȫɽׯ-->����-             -->�ٲ�ҩ��-               " << endl;
	cout << "                         (4/3)   (5/4)                 (8/5)                  " << endl;
}
int nextmap[10][3] = {              //��ͼ����
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
place("�׺��ھ�",0,1,"��׼�����ھֳ���,��׼���׵���"),
place("���ݳ�",0,3,"�����������ݳǣ���������������ҵ��ǣ�������̷����䡣���������Ǳ����һ����������С�������"),
place("����Ⱥɽ",0,5,"������������Ⱥɽ������ɽ�����࣬���нٷ˺�Ұ�޳�û�����к��ǰ����һ��������"),
place("��Ȫɽׯ",0,3,"����������Ȫɽׯ����������Ȫ���ɵ����أ����ɵ���ʮ�ֺ�ս��������Ϊ����ֱ�������������֡�"),
place("����",0,4,"�������˻����������ǳ����̵�������Χ�����ǹ���Ī�⣬��ʱ�̾��衣"),
place("ƽ����ջ",0,4,"��������ƽ����ջ�������Ƕ�����ͨ���ϵ�Ъ�Ŵ��������������ӣ�����а�ɵ��ӵ���Ӱ��"),
place("�䵱ɽ",0,4,"���������䵱ɽ���������䵱����������ʱ�䵱��ֵ���ң�һ���䵱��ͽ���������š�"),
place("������",0,3,"�������������������������ķ�ء������������������������ı����"),
place("�ٲ�ҩ��",0,5,"�������˰ٲ�ҩ�ȣ������ж��ֶ�������ޡ���˵�������û��"),
place("����",0,4,"�������˾��ǣ�Ŀ�ĵؾ�����ǰ�������������Զû����ô��......") };
Enermy enermy[20] = {   ///string name, int level, int HP, int speed, int power, int defense, string plot
Enermy("ͬ�Ž�ʦ", 1, 1, 1, 1, 1,"���������£���ͬ��ʦ���д���������"),
Enermy("ͬ����ʦ", 1, 1, 1, 1, 1,"���������£���ͬ��ʦ���д���������"),
Enermy("ǿ��", 1, 1, 1, 1, 1,"һ��ǿ������ҹɫ�������ĳ��ӣ���в�㽻�����л���"),
Enermy("����", 1, 1, 1, 1, 1,"���������������㣬�������ǿ�ʼ��������"),
Enermy("����", 1, 1, 1, 1, 1,"һ�����������������ǰ������˵������������Ĳ���������͸���һ�������������"),
Enermy("Ұ��", 1, 1, 1, 1, 1,"һȺҰ���ƺ����㵱����ʳ��......"),
Enermy("��Ȫ����", 1, 1, 1, 1, 1,"��ż����Ȫ���ӣ��Է�����������֣��˷ܵ�Ҫ�����д衣"),
Enermy("��Ȫ����", 1, 1, 1, 1, 1,"��ż����Ȫ���ͣ��Է�������������֡�"),
Enermy("�����̳���", 1, 1, 1, 1, 1,"һ�������̳����ߵ������ǰ����˵��Ҫ����ĸ���ҩ��"),
Enermy("�����̻���", 1, 1, 1, 1, 1,"�㷢����һ�������̻��������㣬��Ȼ��֪�������ʲô���������������Ϊǿ��"),
Enermy("а����̽", 1, 1, 1, 1, 1,"�㷢����а����̽����ν��а��������ɱ��"),
Enermy("а��ͷĿ", 1, 1, 1, 1, 1,"а��ͷĿϮ���˿�ջ�����������ǵ���ı�óѡ�"),
Enermy("�䵱��ͽ", 1, 1, 1, 1, 1,"�����ʦ�ŵ��䵱��ͽ�����Ϊ�ܣ����Ƕ������㡣"),
Enermy("��ħ����", 1, 1, 1, 1, 1,"�����䵱��ͽ��Χ���㣬�����ƺ���Щ���Ծ�......"),
Enermy("�����Ѿ�", 1, 1, 1, 1, 1,"�����Ѿ����㷢���˽������������ó�͢���������������С�"),
Enermy("�����ѽ�", 1, 1, 1, 1, 1,"�����ѽ����������뽫�������ڴˡ�"),
Enermy("�ͻ�", 1, 1, 1, 1, 1,"ͻȻ�ڳ���ֻ��쵰׶��棬��·�������ʤ��"),
Enermy("����", 1, 1, 1, 1, 1,"��Ⱥ����������Ϯ�����������ǵĶ�����"),
Enermy("�����̿�", 1, 1, 1, 1, 1,"�����̿ʹ����δ�ð������ȡ��������"),
Enermy("��������", 1, 1, 1, 1, 1,"���������ס��ȥ·���ø߹ٺ�»Ȱ��Ͷ���������Ȼ�ܾ���"),
};
Enermy boss[10] = {
Enermy("ʦ��", 1, 1, 1, 1, 1,"��������ǰ�����ʦ���Է��Ĳ����㣬���ٽ�����Щ���ա�"),
Enermy("��ʥ", 1, 1, 1, 1, 1,"���ݳǵ�ҹɫ�£������еĵ�ʥ�����˳��ǿڣ����ƺ����㻤�͵ĳ�͢���ܷǳ�����Ȥ��"),
Enermy("���ǰ����", 1, 1, 1, 1, 1,"Զ����Ȼ����������ǰ����ɱ�������ǰ�����ᵶ��ǰ��ҪΪ�������±���"),
Enermy("��Ȫɽׯׯ��", 1, 1, 1, 1, 1,"�������뿪ɽׯʱ��������һ���ˬ��Ц������Ȫɽׯׯ���Ṧ�ⲽ��������Ȼֻ�������򵽾��ģ����Ż�����뿪��"),
Enermy("�����̽���", 1, 1, 1, 1, 1,"�������ڳ��ھ������ط��������ƺ�Ҫ�û����׼���̽��������������ֹ���ǡ�"),
Enermy("��ջ�ƹ�", 1, 1, 1, 1, 1,"û�뵽��ջ�ƹ����ѱ�а�̵�������������а�̵�����С�"),
Enermy("�䵱������", 1, 1, 1, 1, 1,"û�뵽��ջ�������ɵ��䵱Ҳ�Ѿ����䣬�䵱�ĸ�����Ͷ���˳�͢���ˣ����ڴ˵ؽ�ɱ�㡣"),
Enermy("����", 1, 1, 1, 1, 1,"��������˺��������α����ߣ������˳�͢�������ֻ���Ƹ����ۣ�ƴ��һ����"),
Enermy("ǧ������", 1, 1, 1, 1, 1,"����͵ؾ���ҡ����������ɫ������������ӿ����ԭ����˵�е�������Ĵ���......"),
Enermy("κ����", 1, 1, 1, 1, 1,"Ļ����ʹ��������......ԭ����һ·�ϵ����ֶ���κ��������ı���������͵�������ı��������֤�ݣ���͢��Σ����ϵ����һս��")
};
void event(int id, Charactor& player)
{

	int type = 0;                      //�¼�����
	if (id != 2 && id != 8 && type == 1);      //�����̵꣨δ����
	else if (type == 2);                    //�¼�������δ����
	else if(type == 0)
	{
		int n = 1;                    //������ɵ���������δ����
		Enermy number;
		int j = 2 * id;                //���ݵ�ǰ��ͼ�����ȡ�������ͣ�δ����
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
void Interface(int id, int way, Charactor &player)                     //����ѡ�����
{
	string tmp;
	int i;
	while (way < site[id].length)
	{
		if (day >= 27)
		{
			cout << "����ʱ�ޣ�����ʧ�ܣ�׼�����������棡" << endl;
            Sleep(3000);
            system("cls");
			break;
		}
		cout << "�˵�ʣ��·��:" << site[id].length - way << ",ʣ������:" << 27 - day << endl;
		cout << "��ѡ��:\n1.������ 2.���� 3.ǰ�� 4.�鿴����״̬ 5.�洢���� ";
		cin >> tmp;
		i = tmp[0] - '0';
		while (i > 4 || i < 1)
		{
			cout << "��Ч���" << endl;
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
void destination(int id, Charactor &player)			//ѡ����һ�ص�
{
	string tmp;
	int j = 1, q = 0;
	if (id != 9)
	{
		cout << "��׼���뿪" << site[id].name << "!\n" << endl;
		mapprint();
		if (nextmap[id][1] != 0)
		{
			cout << "��ѡ����һ�ص�--" << endl;
			for (q=0;nextmap[id][q] != 0 && q < 3;q++) { cout << q + 1 << '.' << site[nextmap[id][q]].name << ' '; }
			cin >> tmp;
			j = tmp[0] - '0';
			while (j > q + 1 || j <1)
			{
				cout << "��Ч���" << endl;
				cin >> tmp;
				j = tmp[0] - '0';
			}
		}
		cout << "����ǰ��" << site[nextmap[id][j - 1]].name << '!' << endl;
		for (int i = 0;i <= 7;i++)
		{
			Sleep(500);
			cout << '>';
		}
		system("cls");
		void adventure(int id, int way, Charactor & player);
		adventure(nextmap[id][j - 1], 0, player);
	}
	if (id == 9) cout << "���ڳɹ�����Ϸʤ����" << endl;
}
void adventure(int id, int way, Charactor & player)      //��ʼð��
{
	site[id].fprint();				                  //��ӡ�ص����
	Interface(id, way, player);                        //����ѡ�����
	if (day >= 27 || player.HP <= 0)					  //�����ع�������
	{
		void start();
		start();
	}
	else destination(id, player);     //ѡ����һ�ص�
}
void start()						 //��ʼ����
{
	string tmp;
	int x;
	cout << "��ӭ�������׺��ھ֡�������Ϸ���㽫����һ����ʦ�����ͳ�͢������Ϣǰ�����ǡ�\n·�Ͻ����������ֵ���,�����������ǵ�ͬʱ��ָ��ʱ�����������\n����Ϊ�˴�����·��:" << endl;
	mapprint();
	cout << "1.�µ���Ϸ 2.��ȡ�浵 3.�˳� ";
	cin >> tmp;
	x = tmp[0] - '0';
	while (x > 3 || x < 1)
	{
		cout << "��Ч���" << endl;
		cin >> tmp;
		x = tmp[0] - '0';
	}
	Charactor player(10, 10, 100, 100);   //ʵ�������
	player.sheet.push_back(playerplan[0]);
	enermy[0].sheet.push_back(enermyplan[0]);
	switch (x)
	{
	case 1:
		system("cls");
		cout << "��ѡ��ְҵ��1.���� 2.���� 3.��ʦ " ;
		cin >> x;
		if (x == 1)player.job(Sword);
		if (x == 2)player.job(Shoot);
		if (x == 3)player.job(Warrior);
		system("cls");
		adventure(0, 0, player);        //��ʼð��
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
