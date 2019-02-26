#include <iostream>

using namespace std;
const char* small_nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char* big_ty[] = {"twenty", "thirty", "forty", "fifty"};

void read_number(int n)
{
	if (n < 20)
		cout << small_nums[n];
	else
	{
		cout << big_ty[n / 10 - 2];
		if (n % 10) cout << ' ' << small_nums[n % 10];
	}
}

void read_time(int h, int m)
{
	read_number(h);
	cout << ' ';
	if (m == 0) cout << " o'clock" << endl;
	else read_number(m);
	cout << endl;
}

int main()
{
	int h, m;
	cin >> h >> m;
	read_time(h, m);
	return 0;
}
