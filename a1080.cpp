#include <iostream>
#include <algorithm>
using namespace std;
// 计算F(n)和F(n+1)除m的余数，分别放入fn和fn1中。
void calcF(int n, int m, int &fn, int &fn1)
{
	if(n == 1)
	{
		fn = 1, fn1 = 1;
	}
	else if (n % 2)
	{
		int fnt, fnt1;
		calcF(n / 2,m, fnt, fnt1);
		fn = (fnt1 * fnt1 + fnt * fnt) % m;
		calcF(n / 2 + 1, m, fnt, fnt1);
		fn1 = (fnt * fnt1 + fnt * ((fnt1 - fnt) + m)) % m;
	}
	else
	{
		int gn, gn1;
		calcF(n / 2, m, gn, gn1);
		fn = (gn *  gn1 + gn * ((gn1 - gn) + m)) % m;
		fn1 = (gn1 * gn1 + gn * gn)%m;
	}
}

int main()
{
	int n, m, fn, fn1;
	cin >> n >> m;
	calcF(n, m, fn, fn1);
	cout << fn % m << endl;
	cout << fn1 % m << endl;
	return 0;
}
