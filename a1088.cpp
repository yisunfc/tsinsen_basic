#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, t, s = 0;
	vector<int> ivec;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		ivec.push_back(t);
	}
	while (!ivec.empty())
	{
		s += ivec.back();
		for (int i = 0; i < ivec.size() - 1; ++i)
		{
			ivec[i] = ivec[i + 1] - ivec[i];
		}
		ivec.erase(--ivec.end());
	}
	cout << s << endl;
	return 0;
}

