#include <iostream>
#include <algorithm>

using namespace std;

int a[20], visited[20], cnt, k;

void dfs(int d)
{
	if (d >= 2) ++cnt;
	if (d >= k) return;
	for (int i = 1; i <= k; ++i)
	{
		if (!visited[i-1])
		{
			a[d] = i;
			int j = 2;
			for ( ;j <= d; ++j)
				if (!((a[j-1] > a[j-2] && a[j] < a[j-2]) || (a[j-1] < a[j-2] && a[j] > a[j-2])))
					break;
			if (d < 2 || j == d+1)
			{
				visited[i-1] = 1;
				dfs(d+1);
				visited[i-1] = 0;
			}
		}
	}
}

int main()
{
	cin >> k;
	dfs(0);
	cout << cnt << endl;
	return 0;
}
