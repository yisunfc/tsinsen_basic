#include <iostream>

using namespace std;

void An(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (i > 1)
		{
			if (i % 2) cout << '+';
			else cout << '-';
		}
		cout << "sin(" << i;
	}
	for (int i = 0; i < n; ++i)
		cout << ')';
}

void Sn(int n, int m, bool flag)
{
	if (n == 0) return;
	if (flag) cout << '(';
	Sn(n-1, m + 1, true);
	An(n);
	cout << '+' << m;
	if (flag) cout << ')';
}

int main()
{
	int n;
	cin >> n;
	Sn(n, 1, false);
	cout << endl;

	return 0;
}
