#include <iostream>
#include <iomanip>
using namespace std;

void PrintBoard();
void SetBoard();
void SetBoard2();
bool CanGo(int y, int x);

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3
};

const int MAX = 100;
int board[MAX][MAX] = { };
int N;

int main()
{
	cin >> N;
	PrintBoard();
	SetBoard();
	cout << endl;
	PrintBoard();

	return 0;
}

void PrintBoard()
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			cout << setfill('0') << setw(2) << board[x][y] << " ";
		}
		cout << endl;
	}
}

void SetBoard()
{
	int num = 1;
	int x = 0, y = 0;
	int xMax = N -1, yMax = N -1;
	int xMin = 0, yMin = 0;

	while (true)
	{
		for (y; y < yMax; y++)
		{
			board[x][y] = num;
			num++;
		}

		for (x; x < xMax; x++)
		{
			board[x][y] = num;
			num++;
		}

		for (y; y > yMin; y--)
		{
			board[x][y] = num;
			num++;
		}

		for (x; x > yMin; x--)
		{
			board[x][y] = num;
			num++;
		}
		x++;
		y++;
		xMax--;
		yMax--;
		xMin++;
		yMin++;

		if (num == (N * N) && (N % 2 == 1))
		{
			board[x][y] = N * N;
			return;
		}
		else if (num >= (N * N) && (N % 2 == 0))
			return;		
	}
}

// 다른 풀이
void SetBoard2()
{
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;

		int nextY;
		int nextX;

		switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;
		case DOWN:
			nextY = y + 1;
			nextX = x;
			break;
		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;
		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		}
		/* switch문 개선
			int dy[] = { 0, 1, 0, -1 };
			int dx[] = { 1, 0, -1, 0 };

			int nextY = y + dy[dir];
			int nextX = x + dx[dir];
		*/

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}
			/* switch문 개선
				dir = (dir + 1) % 4;
			*/
		}
	}
}

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;

	return true;
}