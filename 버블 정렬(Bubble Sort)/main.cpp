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
        // ������ �Ϸ��� �κ��� �����ϰ� ���� ����.
        for (int j = 0; j < n - 1 - i; j++)
        {
            // �� ���� ���� ���� �ε����� ���� ũ�ٸ� �� ���� ��ġ�� �ٲ۴�.
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

        cout << i + 1 << "ȸ��: [ ";
        // ȸ�� ���ึ�� ����� ���
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";

        cout << "]" << endl << endl;
    }

    cout << "���� ��: [ ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "]";

    return 0;
}