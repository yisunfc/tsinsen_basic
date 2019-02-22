#include <iostream>
#include <stack>

using namespace std;

char out[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	int num, base;
	cin >> num >> base;
	if (num == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	stack<char> cs;
	while (num)
	{
		int i = num % base;
		cs.push(out[i]);
		num /= base;
	}
	while (!cs.empty())
	{
		cout << cs.top();
		cs.pop();
	}
	cout << endl;
	return 0;
}
