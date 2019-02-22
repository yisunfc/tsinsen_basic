#include <iostream>

using namespace std;

int main()
{
	int num = 10;
	while (num < 100)
	{
		int i = num / 10;
		int j = num % 10;
		cout << num * 100 + j * 10 + i << endl;
		num++;
	}

	return 0;
}
