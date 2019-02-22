#include <cstdio>

int main()
{
	int a,b,m;
	scanf("%d,%d,%d", &a, &b, &m);
	for (int i = 1; i < m; ++i)
	{
		for (int j = i; j < m; ++j)
		{
			if (a*i + b*j <= m)
				printf("%d,%d\n", i, j);
		}
	}
	return 0;
}
