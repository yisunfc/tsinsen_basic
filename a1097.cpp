#include <iostream>

using namespace std;

int a[5000];
int main()
{
	int L, N;
	cin >> L >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	int mint = 0, maxt = 0;
	for (int i = 0; i < N; ++i)
	{
		mint = max(mint, min(L+1-a[i], a[i]));
		maxt = max(maxt, max(L+1-a[i], a[i]));
	}
	cout << mint << ' ' << maxt << endl;
	return 0;
}

