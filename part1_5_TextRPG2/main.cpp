#include <iostream>
using namespace std;

/*
    호출 순서
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
	srand((unsigned)time(nullptr));	// 랜덤 시드 초기화
	EnterLobby();

	return 0;
}

// 로비에 입장하는 함수
void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장했습니다.");

		// Player 생성 (포인터 사용)
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);

		// 생성한 Player 정보 출력 (참조 사용)
		PrintStatInfo("Player", playerInfo);
		
		// 게임을 시작.
		EnterGame(&playerInfo);
	}
}

// 문자열을 매개변수로 받아 그 값을 출력하는 함수
void PrintMessage(const char* msg)
{
	cout << "*****************************" << endl;
	cout << msg << endl;
	cout << "*****************************" << endl;
}

// Player 생성 함수
void CreatePlayer(StatInfo* playerInfo)
{
	bool ready = false;

	while (ready == false)
	{
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
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

// 생성한 몬스터 or 플레이어의 이름과 정보를 출력하는 함수
void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "*****************************" << endl;
	cout << name << " : HP = " << info.hp << " ATT = " << info.attack << " DEF = " << info.defence << endl;
	cout << "*****************************" << endl;
}

// 게임에 입장하는 함수
void EnterGame(StatInfo* playerInfo)
{
	const int MONSTER_COUNT = 2;

	PrintMessage("게임에 입장했습니다.");
	
	while (true)
	{
		// 생성한 몬스터는 EnterGame 함수 내에서 유효
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);
		
		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			// PrintStatInfo 함수의 2번째 매개변수를 참조 방식이기 때문에 &를 붙이지 않고 사용
			PrintStatInfo("Monster", monsterInfo[i]);
		}

		/*  PrintStatInfo는 참조 방식을 사용하지만 playerInfo 구조체를 매개변수로 받아올 때 포인터를 사용했기에
			*를 붙여 원본 데이터를 매개변수로 넘겨주어야 한다. */ 
		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] 전투 [2] 전투 [3] 도망");
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

// 몬스터를 배열 형태로 생성하는 함수
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

// 몬스터와 플레이어가 전투를 진행하는 함수
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
			PrintMessage("몬스터를 처치했습니다.");
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