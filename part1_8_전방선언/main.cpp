// 기본적으로 지원하는 라이브러리는 < > 안에 작성
#include <iostream>

// 직접 만든 헤더 파일은 " " 안에 작성
#include "Player.h"

using namespace std;

int main()
{
	// Player는 몇 byte 인가?
	// int 2개를 가지고 있으므로 8byte 이다.

	Player p1; // 지역 변수 (stack 영역)

	Player* p2 = new Player(); // 동적할당 (Heap 영역)


	return 0;
}