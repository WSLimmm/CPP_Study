#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Field.h"

using namespace std;


// Ŭ���� �̸� :: �Լ� �̸�
Game::Game() : _player(nullptr), _field(nullptr)
{

}

Game::~Game()
{
	if (_player != nullptr)
		delete _player;

	if (_field != nullptr)
		delete _field;

}

// �� ó�� �ʱ�ȭ �� ȣ���ϴ� �Լ�
void Game::Init()
{
	_field = new Field();

}

// �� �����Ӹ��� ȣ���ϴ� �Լ�
void Game::Update()
{
	// �÷��̾ �������� ������ ����
	if (_player == nullptr)
		CreatePlayer();

	// �÷��̾ ���� ���¶�� ���� �� �ٽ� ����
	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}
	
	
	_field->Update(_player);


}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "-----------------------------" << endl;
		cout << "ĳ���͸� �����ϼ���!" << endl;
		cout << "1) ��� 2) �ü� 3) ����" << endl;
		cout << "-----------------------------" << endl;

		cout << "> ";

		int input = 0;
		cin >> input;

		// ���� �����ڸ� Ȯ���ؾ� �Ѵ�.
		// �ڽ� Ŭ���� -> �θ� Ŭ���� Ÿ�� ��ȯ
		if (input == PT_Knight)
			_player = new Knight();
		else if (input == PT_Archer)
			_player = new Archer();
		else if (input == PT_Mage)
			_player = new Mage();

	}
}