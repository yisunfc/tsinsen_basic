#include <iostream>
#include <algorithm>

using namespace std;

int inversion(int *arr, int n)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (arr[i] > arr[j])
				++cnt;
	return cnt;
}

int main()
{
	int n, a[5][5] = {0}, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	if (n < 5)
	{
		if (n < 4) a[3][3] = 1;
		a[4][4] = 1;
	}
	int index = 0;
	int permutation[] = {1, 2, 3, 4, 5};
	while (index++ < 120)
	{
		int p = 1;
		for (int i = 0; i < 5; ++i)
			p *= a[i][permutation[i] - 1];
		int t = inversion(permutation, 5);
		if (t % 2) sum -= p;
		else sum += p;
		next_permutation(permutation, permutation + 5);
	}

	cout << sum << endl;
	return 0;
}
