// �⺻������ �����ϴ� ���̺귯���� < > �ȿ� �ۼ�
#include <iostream>

// ���� ���� ��� ������ " " �ȿ� �ۼ�
#include "Player.h"

using namespace std;

int main()
{
	// Player�� �� byte �ΰ�?
	// int 2���� ������ �����Ƿ� 8byte �̴�.

	Player p1; // ���� ���� (stack ����)

	Player* p2 = new Player(); // �����Ҵ� (Heap ����)


	return 0;
}