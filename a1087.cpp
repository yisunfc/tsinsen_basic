#include <iostream>
#include <string>
#include <stack>

using namespace std;

void sum(const string &a, const string& b)
{
	stack<int> s;
	const string &ls = (a.size() >= b.size() ? a : b);
	const string &ss = (a.size() < b.size() ? a : b);
	int i = ls.size() - 1, j = ss.size() - 1, c = 0;
	for ( ;j >= 0; --i, --j)
	{
		int x = ls[i] - '0';
		int y = ss[j] - '0';
		int z = (x + y + c) % 10;
		s.push(z);
		if (x + y + c >= 10) c = 1;
		else c = 0;
	}
	for ( ; i >= 0; --i)
	{
		int x = ls[i] - '0';
		int z = (x + c) % 10;
		s.push(z);
		if (x + c >= 10) c = 1;
		else c = 0;
	}
	if (c == 1)
		s.push(1);

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

int main()
{
	string a, b, c;
	cin >> a >> b;
	sum(a, b);
	return 0;
}

