#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n % i == 0) return false;
	return true;
}

set<int> get_prime(int b)
{
	set<int> ret;
	int a = 2;
	while (a <= b)
	{
		if (isPrime(a)) ret.insert(a);
		a++;
	}

	return ret;
}

void parse(const set<int>& s, int a, vector<int>& vec)
{
	if (s.count(a))
	{
		vec.push_back(a);
		return;
	}
	for (int i = 2; i <= sqrt(a); ++i)
	{
		if (a % i == 0)
		{
			if (s.count(i)) vec.push_back(i); else parse(s, i, vec);
			return parse(s, a/i, vec);
		}
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	set<int> s = get_prime(b);
	while (a <= b)
	{
		vector<int> vec;
		parse(s, a, vec);
		sort(vec.begin(), vec.end());
		cout << a << "=";
		for (size_t i = 0; i < vec.size(); ++i)
		{
			if (i != vec.size() - 1) cout << vec[i] << "*";
			else cout << vec[i];
		}
		cout << endl;
		a++;
	}
	return 0;
}
