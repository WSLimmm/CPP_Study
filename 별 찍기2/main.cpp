#include <iostream>
using namespace std;

int main() {
	int input;
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = input; j >= input - i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}