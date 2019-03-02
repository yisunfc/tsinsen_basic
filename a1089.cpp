#include <iostream>

using namespace std;
int a[10000];

void factorial(int n)
{
	a[0] = 1;
	int t, r = 0, index = 0;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= index; ++j)
		{
			t = a[j] * i + r;
			a[j] = t % 10;
			r = t / 10;
		}
		while (r)
		{
			a[++index] = r % 10;
			r /= 10;
		}
	}
	bool bzero = true;
	for (int i = index; i >= 0; --i)
			cout << a[i];
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	factorial(n);
	return 0;
}

