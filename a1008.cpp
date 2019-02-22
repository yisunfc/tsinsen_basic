#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, n;
	scanf("%d", &n);
	int sum = 0, max = -9999, min = 9999;
	while (n-- > 0)
	{
		cin >> a;
		sum += a;
		if (a >= max)
			max = a;
		if (a <= min)
			min = a;
	}
	cout << max << endl << min << endl << sum << endl;
	return 0;
}
