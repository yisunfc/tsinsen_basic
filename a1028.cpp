#include <iostream>

using namespace std;

int gys(int x, int y)
{
	if (x < y) swap(x, y);
	int t = y;
	while (x % y)
	{
		t = x % y; x = y; y = t;
	}
	return t;
}

int gbs(int x, int y)
{
	if (x < y) swap(x, y);
	int z = gys(x, y);
	return x / z * y;
}

int main()
{
	int x,y,z;
	cin >> x >> y >> z;
	switch (z)
	{
	case 1: cout << x+y << endl; break;
	case 2: cout << x-y << endl; break;
	case 3: cout << x*y << endl; break;
	case 4: cout << x/y << endl; break;
	case 5: cout << x%y << endl; break;
	case 6: cout << gys(x, y) << endl; break;
	case 7: cout << gbs(x, y) << endl; break;
	}
	return 0;
}
