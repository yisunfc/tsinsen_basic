#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <vector>
#include <sstream>

using namespace std;
int n, m;

bool anst = true;
bool ansf = true;
bool p[10];
bool a[10];
string x[10], y[10];
char op[10];

bool getvalue(string t) 
{
	int tp;
	if (t[0] == 'P') 
	{
		tp = t[1] - '0';
		return p[tp];
	} 
	else if (t[0] == 'A') 
	{
		tp = t[1] - '0';
		return a[tp];
	}
	return false;
}

void cal(int i)
{
	if (x[i][0] == 'X' && op[i] == '~')
	{
		a[i] = !getvalue(y[i]);
		return;
	}
	else
	{
		bool tx = getvalue(x[i]);
		bool ty = getvalue(y[i]);
		switch (op[i])
		{
		case '>':
			a[i] = (!tx) | ty;
			return;
		case '^':
			a[i] = tx & ty;
			return;
		case 'v':
			a[i] = tx | ty;
		default:
			return;
		}
	}
}


void f(int i)
{
	if (i == n)
	{
		for (int j = 0; j < m; j++)
		{
			cal(j);
		}
		if (a[m - 1]) ansf = false;
		else anst = false;
		return;
	}
	p[i] = true;
	f(i + 1);
	p[i] = false;
	f(i + 1);
}

int main()
{
	cin >> n >> m;
	string ts;

	for (int i = 0; i < m; i++)
	{
		cin >> ts >> x[i] >> op[i] >> y[i];
	}

	f(0);

	if (anst) cout << 1 << endl;
	else if(ansf) cout << -1 << endl;
	else cout << 0 << endl;
	return 0;
}
