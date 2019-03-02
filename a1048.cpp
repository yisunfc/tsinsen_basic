#include <iostream>
using namespace std;

int a[10][10], n;
bool need_change_dir(int i, int j, int dir)
{
	switch (dir)
	{
	case 0: return (i + 1 >= n) || a[i+1][j]; // down
	case 1: return (j + 1 >= n) || a[i][j+1]; // right
	case 2: return (i - 1 < 0 || j - 1 < 0) || a[i-1][j-1]; // left-up
	}
}
void set_next_pos(int &i, int &j, int dir)
{
	switch (dir)
	{
	case 0: ++i; break;
	case 1: ++j; break;
	case 2: --i, --j; break;
	}
}

int main()
{
	int i = 0, j = 0, dir = 0;
	cin >> n;
	for (int s = 0; s < n*(n+1)/2 ; ++s)
	{
		a[i][j] = s + 1;
		if (need_change_dir(i, j, dir))
			dir = (dir + 1) % 3;
		set_next_pos(i, j, dir);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j])
				cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
