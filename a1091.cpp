#include <iostream>
#include <queue>

using namespace std;
deque<int> q;

void output()
{
	for (auto i : q)
		cout << i << ' ';
	cout << endl;
}

void out(int start, int end, int m)
{
	q.push_back(start);
	if (--m == 0)
	{
		output();
		q.pop_back();
		return;
	}

	for (int i = start + 1; i <= end; ++i)
		out(i, end, m);
	q.pop_back();
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		out(i, n, m);
	return 0;
}
