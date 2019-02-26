#include <iostream>

using namespace std;

struct FK
{
	int n;
	bool visited;
};
FK num[205][205];
int n, m;

bool need_change_dir(int i, int j, int dir)
{
	switch (dir)
	{
	case 0: return (i + 1 >= n) || num[i+1][j].visited; // down
	case 1: return (j + 1 >= m) || num[i][j+1].visited; // right
	case 2: return (i - 1 < 0) || num[i-1][j].visited; // up
	case 3: return (j - 1 < 0) || num[i][j-1].visited; // left
	}
}
void set_next_pos(int &i, int &j, int dir)
{
	switch (dir)
	{
	case 0: ++i; break;
	case 1: ++j; break;
	case 2: --i; break;
	case 3: --j; break;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int t;
			cin >> t;
			num[i][j].n = t;
			num[i][j].visited = false;
		}
	}

	int i = 0, j = 0, cnt = 0, dir = 0;
	while (cnt < n * m)
	{
		cout << num[i][j].n;
		num[i][j].visited = true;
		if (++cnt != n * m)
			cout << ' ';
		if (need_change_dir(i, j, dir))
			dir = (dir + 1) % 4;
		set_next_pos(i, j, dir);
	}
	cout << endl;
	return 0;
}

