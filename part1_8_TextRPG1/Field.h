#pragma once
#include "Monster.h"

// ���� ����
class Player;
class Monter;

class Field
{
public:
	Field();
	~Field();

	void Update(Player* player);
	void CreateMonster();

	void StartBattle(Player* player);

private:
	Monster* _monster;

};

