#include <iostream>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

int main() {
	int input, win = 0, lose = 0, winlate = 0;

	while (true)
	{
		srand(time(0));		// 난수 시드 설정
		int com = (rand() % 3) + 1;

		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
		cout << "> 현재 승률: " << winlate << endl;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (com)
			{
			case SCISSORS:
				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
				break;
			case ROCK:
				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
				lose++;
				break;
			case PAPER:
				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
				win++;
				break;
			}
		}
		else if (input == ROCK)
		{
			switch (com)
			{
			case SCISSORS:
				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
				win++;
				break;
			case ROCK:
				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
				break;
			case PAPER:
				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
				lose++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (com)
			{
			case SCISSORS:
				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
				lose++;
				break;
			case ROCK:
				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
				win++;
				break;
			case PAPER:
				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
				break;
			}
		}
		else
		{
			break;
		}

		if (win >= 1 && lose == 0)
		{
			winlate = 100;
		}
		else if (win == 0 && lose >= 0)
		{
			winlate = 0;
		}
		else
		{
			winlate = ((win * 100) / (win + lose));
		}
	}

	return 0;
}