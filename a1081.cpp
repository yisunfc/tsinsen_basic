#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

double fun(double a)
{
	return a*a - 2*a - 3;
}

double getRoot(double (*f)(double), double a, double b)
{
	double fa = f(a);
	double fb = f(b);
	double p = (a + b) / 2;
	while (true)
	{
		double ret = f(p);
		if (abs(ret) < 1e-6)
			return p;
		else
		{
			if (ret * fa > 0) 
			{
				a = p;
				p = (p + b) / 2;
			}
			else 
			{
				b = p;
				p = (a + p) / 2;
			}
		}
	}
}

int main()
{
	double p = getRoot(fun, 0, 10);
	printf("%f\n", p);
	return 0;
}

