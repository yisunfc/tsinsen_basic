#include <iostream>
#include <vector>

using namespace std;

struct Poly
{
	int a; int b;
};

int main()
{
	int k, n;
	cin >> k >> n;
	vector<Poly> data;
	for (int i = 0; i < n; ++i)
	{
		Poly p;
		cin >> p.a >> p.b;
		data.push_back(p);
	}
	cout << "f";
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			Poly& p = data[j];
			if (p.b > 0)
			{
				p.a *= p.b; p.b--;
			}
			else if (p.b == 0)
				p.a = 0;
		}
		cout << "'";
	}
	cout << "(x)=";
	bool zero = true;
	for (int i = 0; i < data.size(); ++i)
	{
		const Poly& p = data[i];
		if (p.a == 0) continue;
		else 
		{
			if (i > 0 && p.a > 0) cout << '+';
			zero = false;
		}
		cout << p.a;
		if (p.b == 1) cout << "*x";
		else if (p.b) cout << "*x^" << p.b;
	}
	if (zero)
		cout << 0;
	cout << endl;

	return 0;
}
