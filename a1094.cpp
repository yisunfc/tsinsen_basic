#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int a, b, c, d;
double func0(double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

double func1(double x)
{
	return 3*a*x*x + 2*b*x + c;
}

int main()
{
	double z;
	cin >> a >> b >> c >> d >> z;
	int n = 1;
	while (true)
	{
		double f0 = func0(z);
		if (abs(f0) < 1e-7)
			break;
		double f1 = func1(z);
		z -= f0/f1;
		++n;
	}

	printf("%.3f %d\n", z, n);
	return 0;
}

