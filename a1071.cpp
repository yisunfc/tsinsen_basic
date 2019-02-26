#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
	int k;
	int s;

	bool operator<(const Person &r) const
	{
		if (s != r.s) return s > r.s;
		else return k < r.k;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Person> data;
	for (int i = 0; i < n; ++i)
	{
		Person p;
		cin >> p.k >> p.s;
		data.push_back(p);
	}
	sort(data.begin(), data.end());
	int cnt = m * 1.5;
	int ds = data[cnt-1].s;
	for (int i = cnt; i < data.size(); ++i)
	{
		if (data[i].s == ds) ++cnt;
		else break;
	}
	cout << ds << ' ' << cnt << endl;
	for (int i = 0; i < cnt; ++i)
		cout << data[i].k << ' ' << data[i].s << endl;
	return 0;
}

