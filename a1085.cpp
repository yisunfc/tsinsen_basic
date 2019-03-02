#include <iostream>
#include <cstring>
#include <map>

using namespace std;
int rule[9][9], cnt = 0, n;

typedef map<int, int> Board;
Board a, b;

bool can_place(int i, int j, bool first)
{
	if (!first && a[i] == j)
		return false;
	Board& self = first ? a : b;
	for (int k = 1; k < i; ++k)
	{
		if (self[k] == j || (self[k]+k == i+j) || (i-j == k-self[k]))
			return false;
	}
	return true;
}
void print_board()
{
	for (int i = 1; i < n; ++i)
	{
		int x = a[i];
		int y = b[i];
		for (int j = 1; j < n; ++j)
		{
			if (x == j)
				cout << 'a';
			else if (y == j)
				cout << 'b';
			else
				cout << '-';
		}
		cout << endl;
	}
	cout << endl;
}

void place_board(int i, bool first)
{
	if (i == n)
	{
		if (!first)
		{
			++cnt;
			//print_board();
		}
		else
		{
			place_board(1, false);
		}
		return;
	}
	Board& board = first ? a : b;
	for (int j = 1; j < n; ++j)
	{
		if (rule[i][j] && can_place(i, j, first))
		{
			board[i] = j;
			place_board(i + 1, first);
		}
	}
}

int main()
{
	cin >> n;
	n++;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
			cin >> rule[i][j];
	}

	place_board(1, true);
	cout << cnt << endl;

	return 0;
}

