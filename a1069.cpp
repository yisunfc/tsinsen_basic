#include <iostream>

using namespace std;
int a[16], visited[16], n, cnt;
int sum_row(int i)
{
	int sum = 0;
	for (int j = 0; j < 4; ++j) sum += a[4*i+j];
	return sum;
}
int sum_colunm(int i)
{
	int sum = 0;
	for (int j = 0; j < 4; ++j) sum += a[4*j+i];
	return sum;
}
int check_diagonal()
{
	return (a[0] + a[5] + a[10] + a[15] == 34) && (a[3] + a[6] + a[9] + a[12] == 34);
}
bool check(int k)
{
	static const int sum = 34;
	if (k == 3) return sum_row(0) == sum;
	else if (k == 7) return sum == sum_row(1);
	else if (k == 11) return sum == sum_row(2);
	else if (k == 15)
		return sum == sum_row(3) && sum == sum_colunm(0) && sum == sum_colunm(1) 
			&& sum == sum_colunm(2) && sum == sum_row(3) && check_diagonal();
	return true;
}

void dfs(int k)
{
	if (k == 16)
	{
		if (++cnt == n)
		{
			for (int i = 0; i < 16; ++i)
			{
				cout << a[i];
				if ((i + 1) % 4 == 0) cout << endl;
				else cout << ' ';
			}
			exit(0);
		}
		return;
	}

	int need = 0;
	if (k % 4 == 3)
	{
		need = 34 - a[k-3] - a[k-2] - a[k-1];
		if ((need > 16 || need < 1) || visited[need-1]) return;
	}
	else if (k >= 12)
	{
		need = 34 - a[k%4] - a[k%4+4] - a[k%4+8];
		if ((need > 16 || need < 1) || visited[need-1]) return;
	}

	if (need)
	{
		a[k] = need;
		if (check(k))
		{
			visited[need-1] = 1;
			dfs(k+1);
			visited[need-1] = 0;
		}
		a[k] = 0;
	}
	else
	{
		for (int i = 1; i <= 16; ++i)
		{
			if (!visited[i-1])
			{
				a[k] = i;
				if (check(k))
				{
					visited[i-1] = 1;
					dfs(k+1);
					visited[i-1] = 0;
				}
				a[k] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;
	dfs(0);
	return 0;
}

