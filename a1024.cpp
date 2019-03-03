#include <iostream>

using namespace std;
int plan = 0, one = 0;

void addtile(int n, int pre, int pre_one)
{
	if (n == 1)
	{
		if (pre != 1)
		{
			plan++, one += pre_one + 1;
		}
	}
	else if (n == 2)
	{
		plan++, one += pre_one;
	}
	else if (n == 3)
	{
		one += pre_one;
		if (pre != 1) addtile(n - 1, 1, pre_one+1);
		addtile(n - 2, 2, pre_one);
		plan++;
	}
	if (n <= 3) return;

	if (pre != 1)
		addtile(n-1, 1, pre_one + 1);
	addtile(n-2, 2, pre_one);
	addtile(n-3, 3, pre_one);
}

int main()
{
	int n;
	cin >> n;
	addtile(n, -1, 0);
	cout << plan << endl << one << endl;
	return 0;
}
