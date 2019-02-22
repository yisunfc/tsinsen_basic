#include<iostream>

using namespace std;

int main()
{
	int i, n;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		n -= i;
	}
	if(i % 2)
		cout << i+1-n << "/" << n << endl;
	else
		cout << n << "/" << i+1-n << endl;
	return 0;
}
