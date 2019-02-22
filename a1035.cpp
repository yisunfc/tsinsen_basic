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
void accumu_prime(int n)
{
	int sum = 0;
	int i = 2;
	while (i <= n)
	{
		if (isPrime(i)) sum += i;
		i++;
	}
	cout << sum << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		accumu_prime(n);
	}
	return 0;
}
