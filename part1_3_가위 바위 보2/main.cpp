#include <iostream>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

int main() {
	int input, win = 0, lose = 0, winlate = 0;

	while (true)
	{
		srand(time(0));		// ���� �õ� ����
		int com = (rand() % 3) + 1;

		cout << "����(1) ����(2) ��(3) ����ּ���!" << endl;
		cout << "> ���� �·�: " << winlate << endl;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (com)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				lose++;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �̰���ϴ�!" << endl;
				win++;
				break;
			}
		}
		else if (input == ROCK)
		{
			switch (com)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				win++;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				lose++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (com)
			{
			case SCISSORS:
				cout << "��(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				lose++;
				break;
			case ROCK:
				cout << "��(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				win++;
				break;
			case PAPER:
				cout << "��(��) vs ��(��ǻ��) �����ϴ�!" << endl;
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