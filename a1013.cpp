#include <iostream>
#include <string>

using namespace std;

int to_decimal(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return 0;
}

int main()
{
	string str;
	cin >> str;
	long long base = 1;
	long long num = 0;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		int j = to_decimal(str[i]);
		num += j * base;
		base *= 16;
	}
	cout << num << endl;
	return 0;
}
