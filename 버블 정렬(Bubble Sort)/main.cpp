#include <iostream>
using namespace std;

int a[10000];
int n, temp;

int main() 
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        // 정렬을 완료한 부분을 제외하고 정렬 진행.
        for (int j = 0; j < n - 1 - i; j++)
        {
            // 두 수를 비교해 왼쪽 인덱스의 값이 크다면 두 값의 위치를 바꾼다.
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

        cout << i + 1 << "회차: [ ";
        // 회차 진행마다 결과를 출력
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";

        cout << "]" << endl << endl;
    }

    cout << "정렬 후: [ ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "]";

    return 0;
}