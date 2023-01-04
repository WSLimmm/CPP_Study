#include <iostream>
using namespace std;

void Swap(int* a, int* b);
void Sort(int numbers[], int count);
void ChooseLotto(int numbers[]);

int main()
{
	// 1. Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(&a, &b);
	cout << a << " " << b << endl;

	// 2. 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int)); // sizeof(numbers) / sizeof(int)는 배열의 크기를 나타냄.
	
	// 3. 로또 생성 함수 만들기
	ChooseLotto(numbers);
	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}

// 1. a의 값과 b의 값을 바꾸는 함수
void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

// 2. 작은 숫자가 먼저 오도록 정렬하는 함수
void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int min = i;
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[min])
				min = j;
		}

		if (i != min)
			Swap(&numbers[i], &numbers[min]);
	}

	return;
}

// 3. 로또 번호 생성 함수
void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6)
	{
		int randValue = (rand() % 45) + 1;		// 1~ 45 사이의 수 생성

		// 중복 체크
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		// 중복이 없는 경우 배열에 추가
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
	return;
}