#pragma once

class Monster; // ���漱��

class Player
{
public:
	void KillMonster();


public:
	int _hp;
	int _attack;

	// Monster _target; Monster ���·� _target ������ �����߱⿡ Monster Ŭ������ ũ���� 12byte��ŭ Player Ŭ������ ũ�Ⱑ �þ��.
	Monster* _target2; // ������ ���·� �����ϸ� �������� ũ���� 4 or 8 byte�� ũ�Ⱑ �����ȴ�. ��, Player�� ũ��� 8 + 4 = 12byte�� �ȴ�.
	// class Monster* _target2; �� ����� ���漱���̴�.


	// Player _target; ���� �߻�
	Player* _target; // ���������� ����
	// ������ ���¸� ������ �߻����� �ʴ� ������
	// ������ ���´� ũ�Ⱑ 4 or 8 ����Ʈ�� �����Ǿ� �ֱ⿡ �Ҵ��� �޸��� ũ�⸦ ���� �� �� ������
	// ������ ���°� �ƴ϶�� Player Ŭ������ ���ǰ� �Ϸ� �Ǿ�� �� ũ�⵵ �������⿡ ������ �߻��Ѵ�.
};

