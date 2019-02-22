#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> price;

	for (int c = 0; c < n; ++c)
	{
		vector<int> vec(m, 0);
		int i = 0, j = m;
		while (j--)
		{
			int p;
			cin >> p;
			vec[i++] = p;
		}
		price.push_back(vec);
	}

	vector<int> ret;
	for (int i = 0; i < m; ++i)
	{
		int s = (price[0][i] == 0 ? 0 : 1);
		int p = price[0][i];
		for (int j = 1; j < n; ++j)
		{
			if (price[j][i] && (price[j][i] <= p || p == 0))
			{
				s = j + 1;
				p = price[j][i];
			}
		}
		ret.push_back(s);
	}

	for (size_t i = 0; i < ret.size() - 1; ++i)
		cout << ret[i] << ' ';
	cout << ret.back() << endl;

	return 0;
}
