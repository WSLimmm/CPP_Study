#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Field.h"

using namespace std;


// 클래스 이름 :: 함수 이름
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

// 맨 처음 초기화 시 호출하는 함수
void Game::Init()
{
	_field = new Field();

}

// 매 프레임마다 호출하는 함수
void Game::Update()
{
	// 플레이어가 존재하지 않으면 진행
	if (_player == nullptr)
		CreatePlayer();

	// 플레이어가 죽은 상태라면 삭제 후 다시 생성
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
		cout << "캐릭터를 생성하세요!" << endl;
		cout << "1) 기사 2) 궁수 3) 법사" << endl;
		cout << "-----------------------------" << endl;

		cout << "> ";

		int input = 0;
		cin >> input;

		// 접근 지정자를 확인해야 한다.
		// 자식 클래스 -> 부모 클래스 타입 변환
		if (input == PT_Knight)
			_player = new Knight();
		else if (input == PT_Archer)
			_player = new Archer();
		else if (input == PT_Mage)
			_player = new Mage();

	}
}