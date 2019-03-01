#include <iostream>

using namespace std;

int main()
{
	int n, a[100], cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j])
			{
				++cnt;
			}
		}
	cout << cnt << endl;
	return 0;
}

