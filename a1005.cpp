#include <iostream>

using namespace std;

int triple(int x)
{
	return x * x * x;
}

int main()
{
	int i = 1, j = 0, k = 0, num = 100;
	do
	{
		if (triple(i) + triple(j) + triple(k) == num)
			cout << num << endl;
		if (++k == 10)
		{
			k = 0;
			if (++j == 10)
			{
				j = 0; ++i;
			}
		}
		num = i * 100 + j * 10 + k;
	}
	while (num < 1000);
}
