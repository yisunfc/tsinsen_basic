#include <iostream>

using namespace std;

const int MAX = 3000 + 5;
int num[MAX];

int root(int x)
{
	while (num[x])
		x = num[x];
	return x;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int cnt = n;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		if (a == b) continue;
		else if (a > b) swap(a, b);

		int root_a = root(a); int root_b = root(b);
		if (root_a != root_b)
		{
			num[root_b] = root_a;
			--cnt;
		}
	}

	cout << cnt << endl;
	return 0;
}

