#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{
	// Mosnter.h �� �������� ������ _hp ������ ��� ����Ǿ� �ִ��� �𸣱⿡ �����ؾ� �Ѵ�. 
	_target2->_hp = 0;

	// Monster.h �� �����ؾ� �Ѵ�.
	_target2->KillMe();
}
