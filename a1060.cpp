#include <iostream>
#include <map>
#include <cmath>

using namespace std;

double ratio1[4], ratio2[4];
int compare[3];
typedef map<int, double> ScoreData;
ScoreData data1, data2;

void dfs(int k, int depth, int sum, double p)
{
	if (depth > 12)
	{
		if (k == 1) data1[sum] += p;
		if (k == 2) data2[sum] += p;
		return;
	}
	for (int i = 7; i <= 10; ++i)
	{
		double ratio = (k == 1 ? ratio1[i-7] : ratio2[i-7]);
		if (abs(ratio) < 1e-6) continue;
		sum += i; p *= ratio;
		dfs(k, depth+1, sum, p);
		p /= ratio; sum -= i;
	}
}

int main()
{
	for (int i = 0; i < 4; ++i) cin >> ratio1[i];
	for (int i = 0; i < 4; ++i) cin >> ratio2[i];
	for (int i = 0; i < 3; ++i) cin >> compare[i];

	dfs(1, 1, 0, 1);
	dfs(2, 1, 0, 1);

	for (int i = 0; i < 3; ++i)
	{
		double r = 0;
		for (auto const &p : data1)
		{
			auto const iter2 = data2.find(p.first - compare[i]);
			if (iter2 != data2.end())
				r += p.second * iter2->second;
		}
		cout << round(r*100) << '%' << endl;
	}

	return 0;
}
