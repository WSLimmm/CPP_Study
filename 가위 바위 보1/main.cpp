#include <iostream>
using namespace std;

int main() {
	int input;

	while (true)
	{
		srand(time(0));
		int com = (rand() % 3) + 1;

		cout << "가위(1) 바위(2) 보(3) 골라주세요!\n>";
		cin >> input;

		if (com == 1 && input == 1)
		{
			cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
		}
		else if (com == 2 && input && 2)
		{
			cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
		}
		else if (com == 3 && input == 3)
		{
			cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
		}
		else if (com == 1 && input == 2)
		{
			cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
		}
		else if (com == 1 && input == 3)
		{
			cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
		}
		else if (com == 2 && input == 1)
		{
			cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
		}
		else if (com == 2 && input == 3)
		{
			cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
		}
		else if (com == 3 && input == 1)
		{
			cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
		}
		else if (com == 3 && input == 2)
		{
			cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
		}
		else { break; }

		cout << endl;
	}

	return 0;
}