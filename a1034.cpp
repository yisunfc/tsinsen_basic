#include <iostream>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int a, b;
	cin >> a >> b;
	set<int> primes;
	for (int i = a; i <= b; ++i)
		if (isPrime(i))
			primes.insert(i);

	bool empty = true;
	for (auto i : primes)
		if (primes.count(i + 2))
		{
			cout << i << ' ' << i + 2 << endl;
			empty = false;
		}

	if (empty) cout << "-1" << endl;
	return 0;
}
