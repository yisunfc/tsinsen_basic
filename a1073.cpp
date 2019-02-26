#include <iostream>

using namespace std;
int a[100][100];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j) a[i][j] *= 2;
			else if (i > j) a[i][j] += a[j][i];
		}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i >= j) cout << a[i][j] << ' ';
			else cout << a[j][i] << ' ';
		}
		cout << endl;
	}
	return 0;
}

