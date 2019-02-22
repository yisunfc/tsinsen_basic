#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> vec;
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		vec.push_back(s);
	}
	static const char DNA[4] = {'A', 'C', 'G', 'T'};
	size_t length = s.size();
	for (size_t i = 0; i < length; ++i)
	{
		int max = 0;
		int cnt[4] = {0};
		for (size_t j = 0; j < vec.size(); ++j)
		{
			switch (vec[j][i])
			{
			case 'A': cnt[0]++; break;
			case 'C': cnt[1]++; break;
			case 'G': cnt[2]++; break;
			case 'T': cnt[3]++; break;
			}
		}
		for (int k = 1; k < 4; ++k)
			if (cnt[max] < cnt[k])
				max = k;
		cout << DNA[max];
	}
	cout << endl;
	return 0;
}
