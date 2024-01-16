#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string str = "H e l l o W o r l d";
	cout << str << " ���ڿ��� ũ��: " << str.length() << endl;


	// str ���ڿ��� ù ��° ���� ����
	str.erase(str.begin());
	cout << str << " ���ڿ��� ũ��: " << str.length() << endl;


	// str ���ڿ��� ������ ���� ����
	str.erase(str.end() - 1);
	cout << str << " ���ڿ��� ũ��: " << str.length() << endl;


	// str ���ڿ��� ���۰� �� ������ ���� ����
	str.erase(str.begin(), str.end());
	cout << str << " ���ڿ��� ũ��: " << str.length() << endl;


	// remove �Լ� ��� �� ������ ������ ������ ���ڿ��� ũ�Ⱑ �پ������ �ʴ´�.
	remove(str.begin(), str.end(), ' ');
	cout << str << " ���ڿ��� ũ��: " << str.length() << endl;


	// remove �Լ��� erase �Լ��� ����Ͽ� ���ڿ��� ���� ����
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	cout << str << " ���ڿ��� ũ��: " << str.length() << endl;

	return 0;
}
