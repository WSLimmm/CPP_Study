#include <iostream>
using namespace std;

int divisor(int x, int y) {		// 최대공약수
	int z = x % y;

	while (z != 0) {
		x = y;
		y = z;
		z = x % y;
	}
	return y;
}

int multiple(int x, int y) {		// 최소공배수
	return (x * y) / divisor(x, y);
}

int main() {
	int a, b, div, mul, temp;	// div 최대공약수  mul 최소공배수
	cin >> a >> b;

	if (a < b) // a가 b보다 작을경우 a와 b의 값을 바꾼다.
	{
		temp = a;
		a = b;
		b = temp;
	}

	div = divisor(a, b);
	mul = multiple(a, b);

	cout << "a의 값: " << a << " b의 값: " << b << endl;
	cout << "최대공약수: " << div << ", 최소공배수: " << mul << endl;

	return 0;
}