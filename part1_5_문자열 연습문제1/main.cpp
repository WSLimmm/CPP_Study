#include <iostream>
using namespace std;

int StrLen(const char* str);
void StrCpy(char* dest, char* src);
void StrCpy2(char* dest, char* src);
void StrCat(char* dest, char* src);
void StrCat2(char* dest, char* src);
int StrCmp(char* a, char* b);
void ReverseStr(char* str);

#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	int len = StrLen(a);
	cout << len << endl;

	//StrCpy(b, a);
	//cout << b << endl;

	//StrCat2(a, b);
	//cout << a << endl;

	//cout << StrCmp(a, b) << endl;

	ReverseStr(a);
	cout << a << endl;
	



	return 0;
}

int StrLen(const char* str)
{
	int count = 0;
	while (str[count] != '\0')
		count++;

	return count;
}

// StrCpy 배열 방식
void StrCpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

// SrtCpy 포인터 방식
void StrCpy2(char* dest, char* src)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';
}

// StrCat 배열 방식
void StrCat(char* dest, char* src)
{
	int i = 0, j = 0;
	while (dest[i] != '\0')		// 이전에 만든 StrLen 함수를 사용할 수도 있다.
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
}

// StrCat 포인터 방식
void StrCat2(char* dest, char* src)
{
	int len = StrLen(dest);	// 이전에 만든 StrLen 함수를 사용.
	while (*src != '\0')
	{
		*(dest + len) = *src;
		dest++;
		src++;
	}

	*(dest + len) = '\0';
}

// 문자열 비교 함수
int StrCmp(char* a, char* b)
{
	int i = 0;
	while (true)
	{
		if (a[i] < b[i])
			return -1;
		else if (a[i] > b[i])
			return 1;
		else
			i++;

		if (a[i] == 0 && b[i] == 0)
			return 0;
	}
}

// 문자열 뒤집기
void ReverseStr(char* str)
{
	const int size = StrLen(str);

	for (int i = 0; i < size / 2; i++)
	{
		char temp = str[i];
		str[i] = str[(size - 1) - i];
		str[(size - 1) - i] = temp;
	}
}