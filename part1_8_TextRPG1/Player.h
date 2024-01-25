#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

// 헤더 파일에서는 정의만 하고 cpp 파일에서 구현하는 것이 일반적.
class Player : public Creature // 다른 헤더 파일에 존재하는 클래스를 사용하기 위해 include를 사용한다.
{
public:
	// Player 생성자 호출 시 playerType을 매개변수로 받고 그 값을 _playerType 변수에 저장한다.
	Player(int playerType) : Creature(CT_PLAYER), _playerType(playerType)
	{

	}

	// 상속 관계에서 부모 클래스의 소멸자는 virtual을 붙여 가상 함수 형식으로 구현한다.
	virtual ~Player()
	{

	}

	virtual void PrintInfo();

protected:
	int _playerType;
};


// 클래스가 방대해지면 헤더 파일과 cpp 파일로 따로 구분하는 것이 좋다.
class Knight : public Player
{
public:
	// Knight 클래스를 호출하면 Player 클래스의 _playerType에 PT_Knight(1)를 저장한다.
	Knight() : Player(PT_Knight)
	{
		_hp = 150;
		_attack = 10;
		_defence = 5;
	}

};

class Archer : public Player
{
public:
	// Archer 클래스를 호출하면 Player 클래스의 _playerType에 PT_Archer(2)를 저장한다.
	Archer() : Player(PT_Archer)
	{
		_hp = 80;
		_attack = 15;
		_defence = 3;
	}

};

class Mage : public Player
{
public:
	// Mage 클래스를 호출하면 Player 클래스의 _playerType에 PT_Mage(3)를 저장한다.
	Mage() : Player(PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 0;
	}

};

