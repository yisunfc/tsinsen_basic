#include <iostream>

using namespace std;
void count(int n, int idx)
{
	int num = 100;
	while (num < 1000)
	{
		int i = num / 100;
		int j = (num / 10) % 10;
		int k = num % 10;

		if (idx == 5)
		{
			if ( i *2 + j * 2 + k == n)
				cout << num * 100 + j * 10 + i << endl;
		}
		else if (idx == 6)
		{
			if ((i + j + k) * 2 == n)
				cout << num * 1000 + k * 100 + j * 10 + i << endl;
		}

		num++;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	count(n,5);
	count(n,6);

	return 0;
}
