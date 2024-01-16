#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string str = "H e l l o W o r l d";
	cout << str << " 문자열의 크기: " << str.length() << endl;


	// str 문자열의 첫 번째 문자 제거
	str.erase(str.begin());
	cout << str << " 문자열의 크기: " << str.length() << endl;


	// str 문자열의 마지막 문자 제거
	str.erase(str.end() - 1);
	cout << str << " 문자열의 크기: " << str.length() << endl;


	// str 문자열의 시작과 끝 사이의 원소 제거
	str.erase(str.begin(), str.end());
	cout << str << " 문자열의 크기: " << str.length() << endl;


	// remove 함수 사용 시 공백이 삭제가 되지만 문자열의 크기가 줄어들지는 않는다.
	remove(str.begin(), str.end(), ' ');
	cout << str << " 문자열의 크기: " << str.length() << endl;


	// remove 함수와 erase 함수를 사용하여 문자열의 공백 제거
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	cout << str << " 문자열의 크기: " << str.length() << endl;

	return 0;
}
