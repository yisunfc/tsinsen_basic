#include <iostream>

using namespace std;

int plan = 0, one = 0;

void addtile(int n, int pre)
{
	cout << "addtile n:" << n << " pre:" << pre << " plan:" << plan << " one:" << one << endl;
	if (n == 1)
	{
		if (pre != 1)
			one++, plan++;
		return;
	}
	else if (n == 2)
	{
		plan++;
		return;
	}
	else if (n == 3)
	{
		if (pre == 1) plan += 2;
		else plan += 3;
		one += 2;
		return;
	}

	if (pre != 1)
	{
		one++;
		addtile(n-1, 1);
	}
	addtile(n-2, 2);
	addtile(n-3, 3);
}

int main()
{
	int n;
	cin >> n;
	addtile(n, -1);
	cout << plan << endl << one << endl;

	return 0;
}
