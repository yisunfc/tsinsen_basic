#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	stringstream iss;
	iss << str;
	int ret, i;
	char op;
	iss >> ret;
	while (true)
	{
		iss >> op >> i;
		if (op == '+') ret += i;
		else if (op == '-') ret -= i;
		else if (op == '=') break;
	}
	cout << ret << endl;
	return 0;
}
