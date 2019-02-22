#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> vec;

		while (n--)
		{
			int i;
			cin >> i;
			vec.push_back(i);
		}

		while(m--)
		{
			int x, y;
			cin >> x >> y;
			swap(vec[x-1], vec[y-1]);
		}

		for (auto i : vec)
			cout << i << endl;
	}
}
