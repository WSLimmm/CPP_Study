#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{
	// Mosnter.h 를 선언하지 않으면 _hp 변수가 어디에 저장되어 있는지 모르기에 선언해야 한다. 
	_target2->_hp = 0;

	// Monster.h 를 선언해야 한다.
	_target2->KillMe();
}
