#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > q;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	int sum = 0, a, b, c;
	while (q.size() > 1)
	{
		a = q.top();
		q.pop();
		b = q.top();
		c = a + b;
		q.pop();
		q.push(a + b);
		sum += c;
	}
	cout << sum << endl;

	return 0;
}

