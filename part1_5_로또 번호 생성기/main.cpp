#include <iostream>
using namespace std;

void Swap(int* a, int* b);
void Sort(int numbers[], int count);
void ChooseLotto(int numbers[]);

int main()
{
	// 1. Swap �Լ� �����
	int a = 1;
	int b = 2;
	Swap(&a, &b);
	cout << a << " " << b << endl;

	// 2. ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int)); // sizeof(numbers) / sizeof(int)�� �迭�� ũ�⸦ ��Ÿ��.
	
	// 3. �ζ� ���� �Լ� �����
	ChooseLotto(numbers);
	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}

// 1. a�� ���� b�� ���� �ٲٴ� �Լ�
void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

// 2. ���� ���ڰ� ���� ������ �����ϴ� �Լ�
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

// 3. �ζ� ��ȣ ���� �Լ�
void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6)
	{
		int randValue = (rand() % 45) + 1;		// 1~ 45 ������ �� ����

		// �ߺ� üũ
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		// �ߺ��� ���� ��� �迭�� �߰�
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
	return;
}