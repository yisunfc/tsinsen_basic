#include <iostream>

using namespace std;

int main()
{
	int a,b,c,d, n;
	cin >> n;
	a = n / 1000;
	b = (n / 100) % 10;
	c = (n / 10) % 10;
	d = n % 10;

	a = (a + 5) % 10;
	b = (b + 5) % 10;
	c = (c + 5) % 10;
	d = (d + 5) % 10;
	cout << d * 1000 + c * 100 + b * 10 + a << endl;

	return 0;
}
