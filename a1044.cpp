#include <iostream>

using namespace std;

int fib(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 2;
	int j = 1, k = 1, sum = 2;
	for (int i = 3; i <= n; ++i)
	{
		j += k;
		k = j - k;
		sum += j;
	}

	return sum;
}

int main()
{
	int n;
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		cout << fib(n) << endl;
	}

	return 0;
}
