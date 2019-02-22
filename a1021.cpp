#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct set
{
	set(){};
	bool insert(int i)
	{
		for (auto j : vec)
			if (j == i) return false;
		vec.push_back(i);
	}
	bool empty() const
	{
		return size() == 0;
	}
	size_t size() const
	{
		return vec.size();
	}
	void sort()
	{
		std::sort(vec.begin(), vec.end());
	}
	int operator[](size_t i) const
	{
		return vec[i];
	}

	vector<int> vec;
};
set operator + (const set &a, const set &b)
{
	set ret(a);
	for (auto i : b.vec)
		ret.insert(i);
	ret.sort();
	return ret;
}
ostream& operator << (ostream& os, const set &s)
{
	if (s.empty())
		return os;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (i != s.size() - 1)
			os << s[i] << ' ';
		else
			os << s[i];
	}
	os << endl;

	return os;
}
set union_set(const set &a, const set &b) 
{
	set ret;
	for (size_t i = 0, j = 0; i < a.size() && j < b.size(); )
	{
		if (a[i] == b[j])
		{
			ret.insert(a[i]);
			++i, ++j;
		}
		else if (a[i] < b[j]) ++i;
		else ++j;
	}
	return ret;
}
set minus_set(const set &a, const set &b) 
{
	set ret;
	size_t i = 0;
	for (size_t j = 0;i < a.size() && j < b.size(); )
	{
		if (a[i] == b[j])
			++i, ++j;
		else if (a[i] < b[j])
			ret.insert(a[i++]);
		else ++j;
	}
	while (i < a.size())
		ret.insert(a[i++]);
	return ret;
}
void get_set(int n, set& ret)
{
	while (n--)
	{
		int i;
		cin >> i;
		ret.insert(i);
	}
}

int main()
{
	int n,m;
	set a,b;
	cin >> n;
	get_set(n, a);
	cin >> m;
	get_set(m, b);
	a.sort(); b.sort();
	cout << union_set(a, b);
	cout << a + b;
	cout << minus_set(a, b);
	return 0;
}
