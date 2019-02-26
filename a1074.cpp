#include <iostream>

using namespace std;

int main()
{
	int a[100][100];
	int b[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		cin >> a[i][j];

	for (int i = 0; i < n; ++i)
		cin >> b[i];

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
			sum += a[i][j] * b[j];
		cout << sum << endl;
	}
	return 0;
}
