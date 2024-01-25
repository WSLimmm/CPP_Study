#pragma once

// ���� ����: Ŭ������ �����ϱ� ���� �̸� ���� �� ���� ��.
class Player;
class Field;

// Game Ŭ������ Player Ŭ������ has - a ����, ���԰��� (Game�� Player�� �����Ѵ�.) (��� X)
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	// Player _player ���� ��� Ŭ���� ���°� �ƴ� ������ ���·� �����ؾ� �Ѵ�.
	// ��� Ŭ���� ���·� �����ϸ� �������� �ʹ� �������� ����.
	Player* _player;
	Field* _field;

};

