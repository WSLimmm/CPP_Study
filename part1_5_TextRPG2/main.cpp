#include <iostream>
using namespace std;

/*
    ȣ�� ����
	main
	- EnterLobby (PlayerInfo)
	-- CreatePlayer
	-- EnterGame (MonsterInfo)
	--- CreateMonsters
	--- EnterBattle
*/

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3
};

struct StatInfo
{
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
	srand((unsigned)time(nullptr));	// ���� �õ� �ʱ�ȭ
	EnterLobby();

	return 0;
}

// �κ� �����ϴ� �Լ�
void EnterLobby()
{
	while (true)
	{
		PrintMessage("�κ� �����߽��ϴ�.");

		// Player ���� (������ ���)
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);

		// ������ Player ���� ��� (���� ���)
		PrintStatInfo("Player", playerInfo);
		
		// ������ ����.
		EnterGame(&playerInfo);
	}
}

// ���ڿ��� �Ű������� �޾� �� ���� ����ϴ� �Լ�
void PrintMessage(const char* msg)
{
	cout << "*****************************" << endl;
	cout << msg << endl;
	cout << "*****************************" << endl;
}

// Player ���� �Լ�
void CreatePlayer(StatInfo* playerInfo)
{
	bool ready = false;

	while (ready == false)
	{
		PrintMessage("ĳ���� ����â");
		PrintMessage("[1] ��� [2] �ü� [3] ����");
		cout << "> ";

		int input;
		cin >> input;

		switch (input)
		{
		case PT_Knight:
			playerInfo->hp = 100;
			playerInfo->attack = 10;
			playerInfo->defence = 5;
			ready = true;
			break;
		case PT_Archer:
			playerInfo->hp = 80;
			playerInfo->attack = 15;
			playerInfo->defence = 3;
			ready = true;
			break;
		case PT_Mage:
			playerInfo->hp = 50;
			playerInfo->attack = 25;
			playerInfo->defence = 1;
			ready = true;
			break;
		}
	}
}

// ������ ���� or �÷��̾��� �̸��� ������ ����ϴ� �Լ�
void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "*****************************" << endl;
	cout << name << " : HP = " << info.hp << " ATT = " << info.attack << " DEF = " << info.defence << endl;
	cout << "*****************************" << endl;
}

// ���ӿ� �����ϴ� �Լ�
void EnterGame(StatInfo* playerInfo)
{
	const int MONSTER_COUNT = 2;

	PrintMessage("���ӿ� �����߽��ϴ�.");
	
	while (true)
	{
		// ������ ���ʹ� EnterGame �Լ� ������ ��ȿ
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);
		
		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			// PrintStatInfo �Լ��� 2��° �Ű������� ���� ����̱� ������ &�� ������ �ʰ� ���
			PrintStatInfo("Monster", monsterInfo[i]);
		}

		/*  PrintStatInfo�� ���� ����� ��������� playerInfo ����ü�� �Ű������� �޾ƿ� �� �����͸� ����߱⿡
			*�� �ٿ� ���� �����͸� �Ű������� �Ѱ��־�� �Ѵ�. */ 
		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] ���� [2] ���� [3] ����");
		int input;
		cin >> input;

		if (input == 1 || input == 2)
		{
			int index = input - 1;
			bool victory = EnterBattle(playerInfo, &monsterInfo[index]);

			if (victory == false)
				break;
		}
	}
}

// ���͸� �迭 ���·� �����ϴ� �Լ�
void CreateMonsters(StatInfo monsterInfo[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int randValue = (rand() % 3) + 1;

		switch (randValue)
		{
		case MT_Slime:
			monsterInfo[i].hp = 30;
			monsterInfo[i].attack = 5;
			monsterInfo[i].defence = 1;
			break;
		case MT_Orc:
			monsterInfo[i].hp = 40;
			monsterInfo[i].attack = 8;
			monsterInfo[i].defence = 2;
			break;
		case MT_Skeleton:
			monsterInfo[i].hp = 50;
			monsterInfo[i].attack = 15;
			monsterInfo[i].defence = 3;
			break;
		}
	}
}

// ���Ϳ� �÷��̾ ������ �����ϴ� �Լ�
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
	while (true)
	{
		int damage = playerInfo->attack - monsterInfo->defence;
		if (damage < 0)
			damage = 0;

		monsterInfo->hp -= damage;
		if (monsterInfo->hp < 0)
			monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0)
		{
			PrintMessage("���͸� óġ�߽��ϴ�.");
			return true;
		}

		damage = monsterInfo->attack = playerInfo->defence;
		if (damage < 0)
			damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0)
			playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0)
		{
			PrintMessage("Game Over");
			return false;
		}
	}
}