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

	virtual void PrintInfo() = 0; // 추상적인 가상함수라는 뜻

	void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; } // 함수가 짧으면 헤더 파일에 구현해도 상관없다.


// 외부에서 사용하고 싶다면 get, set 함수를 통해서 가능
protected:
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;
};

