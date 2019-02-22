#include <iostream>

using namespace std;

int main()
{
	int a[20][20];
	int n, t;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> t;
			a[i][j] = t;
		}

	bool first = true;
	for (int i = 0; i < n; ++i)
	{
		int good = 0;
		for (int j = 0; j < n; ++j)
			if (a[j][j]) ++ good;
		if (good >= (n+1) / 2)
		{
			if (!first) cout << ' '; else first = false;
			cout << i + 1;
		}
	}
	cout << endl;

	return 0;
}
