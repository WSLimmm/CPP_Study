#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

// ��� ���Ͽ����� ���Ǹ� �ϰ� cpp ���Ͽ��� �����ϴ� ���� �Ϲ���.
class Player : public Creature // �ٸ� ��� ���Ͽ� �����ϴ� Ŭ������ ����ϱ� ���� include�� ����Ѵ�.
{
public:
	// Player ������ ȣ�� �� playerType�� �Ű������� �ް� �� ���� _playerType ������ �����Ѵ�.
	Player(int playerType) : Creature(CT_PLAYER), _playerType(playerType)
	{

	}

	// ��� ���迡�� �θ� Ŭ������ �Ҹ��ڴ� virtual�� �ٿ� ���� �Լ� �������� �����Ѵ�.
	virtual ~Player()
	{

	}

	virtual void PrintInfo();

protected:
	int _playerType;
};


// Ŭ������ ��������� ��� ���ϰ� cpp ���Ϸ� ���� �����ϴ� ���� ����.
class Knight : public Player
{
public:
	// Knight Ŭ������ ȣ���ϸ� Player Ŭ������ _playerType�� PT_Knight(1)�� �����Ѵ�.
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
	// Archer Ŭ������ ȣ���ϸ� Player Ŭ������ _playerType�� PT_Archer(2)�� �����Ѵ�.
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
	// Mage Ŭ������ ȣ���ϸ� Player Ŭ������ _playerType�� PT_Mage(3)�� �����Ѵ�.
	Mage() : Player(PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 0;
	}

};

