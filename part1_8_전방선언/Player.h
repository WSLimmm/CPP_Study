#pragma once

class Monster; // 전방선언

class Player
{
public:
	void KillMonster();


public:
	int _hp;
	int _attack;

	// Monster _target; Monster 형태로 _target 변수를 선언했기에 Monster 클래스의 크기인 12byte만큼 Player 클래스의 크기가 늘어난다.
	Monster* _target2; // 포인터 형태로 선언하면 포인터의 크기인 4 or 8 byte로 크기가 고정된다. 즉, Player의 크기는 8 + 4 = 12byte가 된다.
	// class Monster* _target2; 이 방법도 전방선언이다.


	// Player _target; 오류 발생
	Player* _target; // 정상적으로 실행
	// 포인터 형태만 오류가 발생하지 않는 이유는
	// 포인터 형태는 크기가 4 or 8 바이트로 고정되어 있기에 할당할 메모리의 크기를 쉽게 알 수 있지만
	// 포인터 형태가 아니라면 Player 클래스가 정의가 완료 되어야 그 크기도 정해지기에 오류가 발생한다.
};

