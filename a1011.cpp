#include <iostream>
#include <stack>

using namespace std;

char out[] = "0123456789ABCDEF";

int main()
{
	int num;
	cin >> num;
	if (num == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	stack<char> cs;
	while (num)
	{
		int i = num % 16;
		cs.push(out[i]);
		num /= 16;
	}
	while (!cs.empty())
	{
		cout << cs.top();
		cs.pop();
	}
	cout << endl;
	return 0;
}
