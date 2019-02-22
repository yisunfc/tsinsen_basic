#include <iostream>

using namespace std;

const char* basic[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const char* unit1[] = {"yi", "wan"};
const char* unit2[] = {"qian", "bai", "shi"};

void read(int n, bool first, bool last)
{
	if (n == 0)
	{
		if (first) return; else if (!last) cout << "ling ";
	}
	if (n > 10 && n < 20)
	{
		cout << "shi " << basic[n % 10] << ' '; return;
	}
	int q = n / 1000;
	int b = (n / 100) % 10;
	int s = (n / 10) % 10;
	int g = n % 10;

	bool zero = true;
	if (q) 
	{
		cout << basic[q] << ' ' << unit2[0] << ' ';
		zero = false;
	}
	if (b) 
	{
		if ((!first || !zero) && !q) cout << "ling ";
		cout << basic[b] << ' ' << unit2[1] << ' '; 
		zero = false;
	}
	if (s) 
	{
		if ((!first || !zero) && !b) cout << "ling ";
		if (s != 1)
			cout << basic[s] << ' ';
		cout << unit2[2] << ' '; 
		zero = false;
	}
	if (g) 
	{
		if ((!first || !zero) && !s) cout << "ling ";
		cout << basic[g] << ' ';
		zero = false;
	}
}

int main()
{
	int n, yi, wan, ge;
	cin >> n;
	yi = n / 100000000;
	wan = (n / 10000) % 10000;
	ge = n % 10000;
	if (n == 0)
	{
		cout << "ling" << endl; return 0;
	}

	if (yi)
	{
		read(yi, true, false);
		cout << unit1[0] << ' ';
	}
	if (wan)
	{
		read(wan, yi == 0, false);
		cout << unit1[1] << ' ';
	}
	read(ge, yi == 0 && wan == 0, true);
	cout << endl;

	return 0;
}
