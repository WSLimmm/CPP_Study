#pragma once
// 플레이어와 몬스터가 공통으로 갖는 정보를 위한 클래스

enum CreatureType
{
	CT_PLAYER = 0,
	CT_MONSTER = 1
};

class Creature
{
public:
	Creature(int creatureType)
		: _creatureType(creatureType), _hp(0), _attack(0), _defence(0)
	{

	}

	virtual ~Creature()
	{

	}

// 외부에서 사용하고 싶다면 get, set 함수를 통해서 가능
protected:
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;
};

