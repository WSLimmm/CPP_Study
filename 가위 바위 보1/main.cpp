#include <iostream>
using namespace std;

int main() {
	int input;

	while (true)
	{
		srand(time(0));
		int com = (rand() % 3) + 1;

		cout << "����(1) ����(2) ��(3) ����ּ���!\n>";
		cin >> input;

		if (com == 1 && input == 1)
		{
			cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
		}
		else if (com == 2 && input && 2)
		{
			cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
		}
		else if (com == 3 && input == 3)
		{
			cout << "��(��) vs ��(��ǻ��) �����ϴ�!" << endl;
		}
		else if (com == 1 && input == 2)
		{
			cout << "����(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
		}
		else if (com == 1 && input == 3)
		{
			cout << "��(��) vs ����(��ǻ��) �����ϴ�!" << endl;
		}
		else if (com == 2 && input == 1)
		{
			cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
		}
		else if (com == 2 && input == 3)
		{
			cout << "��(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
		}
		else if (com == 3 && input == 1)
		{
			cout << "����(��) vs ��(��ǻ��) �̰���ϴ�!" << endl;
		}
		else if (com == 3 && input == 2)
		{
			cout << "����(��) vs ��(��ǻ��) �����ϴ�!" << endl;
		}
		else { break; }

		cout << endl;
	}

	return 0;
}