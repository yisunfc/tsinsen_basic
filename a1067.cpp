#include <iostream>
using namespace std;
int main()
{
	unsigned long long g = 0, h = 1;
	int i = 1, s, t;
	unsigned long long a, b, c, d, module;
	cin >> s >> t;
	cin >> a >> b >> c >> d;
	module = a*b*c*d;
	while (i <= t)
	{   
		if (i >= s && h%a && h%b && h%c && h%d)
			cout << i << ' ';
		h %= module;
		g %= module;  
		h = h + g;
		g = h - g;                                                                                                                                         
		++i;
	}   
	cout << endl;
	return 0;
}

