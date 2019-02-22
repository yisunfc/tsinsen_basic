#include <iostream>

using namespace std;

int recur(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	else if (n <= 20 && n >= 4) return recur(n-1) + recur(n-2) + recur(n-3);
	else return 0;
}

int main()
{
	int n;
	cin >> n;
	cout << recur(n) << endl;

	return 0;
}

