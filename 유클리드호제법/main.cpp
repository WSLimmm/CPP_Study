#include <iostream>
using namespace std;

int divisor(int x, int y) {		// �ִ�����
	int z = x % y;

	while (z != 0) {
		x = y;
		y = z;
		z = x % y;
	}
	return y;
}

int multiple(int x, int y) {		// �ּҰ����
	return (x * y) / divisor(x, y);
}

int main() {
	int a, b, div, mul, temp;	// div �ִ�����  mul �ּҰ����
	cin >> a >> b;

	if (a < b) // a�� b���� ������� a�� b�� ���� �ٲ۴�.
	{
		temp = a;
		a = b;
		b = temp;
	}

	div = divisor(a, b);
	mul = multiple(a, b);

	cout << "a�� ��: " << a << " b�� ��: " << b << endl;
	cout << "�ִ�����: " << div << ", �ּҰ����: " << mul << endl;

	return 0;
}