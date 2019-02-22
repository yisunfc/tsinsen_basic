#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, n;
	scanf("%d", &n);
	int sum = 0, max = -999, max2 = -999, min = 999, min2 = 999;
	while (n-- > 0)
	{
		cin >> a;
		sum += a * a;
		if (a > max) 
		{
			max2 = max;
			max = a;
		}
		else if (a > max2) max2 = a;

		if (a < min) 
		{
			min2 = min;
			min = a;
		}
		else if (a < min2) min2 = a;
	}
	cout << max2 << endl << min2 << endl << sum << endl;
	return 0;
}
