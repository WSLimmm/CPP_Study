#pragma once

// 전방 선언: 클래스를 구현하기 전에 미리 선언만 해 놓은 것.
class Player;
class Field;

// Game 클래스와 Player 클래스는 has - a 관계, 포함관계 (Game은 Player를 포함한다.) (상속 X)
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	// Player _player 같은 멤버 클래스 형태가 아닌 포인터 형태로 구현해야 한다.
	// 멤버 클래스 형태로 구현하면 의존성이 너무 강해지기 때문.
	Player* _player;
	Field* _field;

};

