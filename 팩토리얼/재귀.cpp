#include <iostream>
using namespace std;

int factorial(int num)
{
	if (num <= 1)
		return 1;

	return num * factorial(num - 1);
}

int main()
{
	int n, result;

	cin >> n;
	result = factorial(n);

	cout << n << "!: " << result << endl;

	return 0;
}