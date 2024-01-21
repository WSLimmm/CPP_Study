#include <iostream>
using namespace std;

int factorial(int num)
{
	int result = 1;

	for (int i = num; i > 0; i--)
		result *= i;

	return result;
}

int main()
{
	int n, result;
	
	cin >> n;
	result = factorial(n);

	cout << n << "!: " << result << endl;

	return 0;
}