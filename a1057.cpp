#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string ret = "A";
	for (int i = 1; i < n; ++i)
	{
		char c = 'A' + i;
		ret = ret + c + ret;
	}
	cout << ret << endl;

	return 0;
}
