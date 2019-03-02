#include <iostream>
#include <deque>

using namespace std;
int n, m;

void print(const deque<int> &ans)
{
	cout << n << '=';
	int i = 0;
	for (auto a : ans)
	{
		if (i++) cout << '+';
		cout << a;
	}
	cout << endl;
}

void dfs(deque<int> &ans, int sum)
{
	if (sum == n)
	{
		print(ans);
		return;
	}
	for (int i = 1; i <= n - sum; ++i)
	{
		ans.push_back(i);
		sum += i;
		dfs(ans, sum);
		ans.pop_back();
		sum -= i;
	}
}

void dfs2(deque<int> &ans, int sum, int s)
{
	if (sum == n)
	{
		print(ans);
		return;
	}
	for (int i = s; i <= n - sum; ++i)
	{
		ans.push_back(i);
		sum += i;
		dfs2(ans, sum, i);
		sum -= i;
		ans.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	deque<int> ans;
	int sum = 0;
	if (m == 1)
		dfs(ans, sum);
	else if (m == 2)
		dfs2(ans, sum, 1);
	return 0;
}

