#include <iostream>
#include <vector>

using namespace std;
enum DIRECT
{
	RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3,
};
typedef vector<int> IVEC;
typedef vector<IVEC> IIVEC;
int N = 0;

int& get_num(IIVEC& vec, int i, int j) { return vec[i][j]; }
bool valid_pos(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }
int change_dir(int dir) { return (dir + 1) % 4; }

void get_next_pos(IIVEC &iivec, int &i, int &j, int &dir)
{
	int a = i, b = j;
	switch (dir)
	{
	case UP: --a; break;
	case DOWN: ++a; break;
	case LEFT: --b; break;
	case RIGHT: ++b; break;
	}
	if (valid_pos(a, b) && get_num(iivec, a, b) == 0)
	{
		i = a, j = b; return;
	}
	else
	{
		dir = change_dir(dir);
		get_next_pos(iivec, i, j, dir);
	}
}

void draw(int n)
{
	IIVEC iivec;
	for (size_t i = 0; i < n; ++i)
	{
		IVEC ivec(n, 0);
		iivec.push_back(ivec);
	}

	int i = 0, j = 0, dir = RIGHT, cur = 0;
	while (true)
	{
		get_num(iivec, i, j) = ++cur;
		if (cur == n * n) break;
		get_next_pos(iivec, i, j, dir);
	}

	for (auto const &vec : iivec)
	{
		for (size_t i = 0; i < vec.size(); ++i)
		{
			if (i != vec.size() - 1) cout << vec[i] << ' ';
			else cout << vec[i];
		}
		cout << endl;
	}
}

int main()
{
	cin >> N;
	draw(N);
	return 0;
}
