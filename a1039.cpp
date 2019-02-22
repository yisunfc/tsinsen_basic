#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec;
	int n;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		ivec.push_back(t);
	}
	vector<int> ivec2;
	for (size_t i = 1; i < ivec.size(); ++i)
	{
		int j = abs(ivec[i] - ivec[i-1]);
		ivec2.push_back(j);
	}
	bool happy = true;
	sort(ivec2.begin(), ivec2.end());
	for (size_t i = 0; i < ivec2.size(); ++i)
	{
		if (i+1 != ivec2[i])
		{
			happy = false; break;
		}
	}
	if (happy) cout << "I'm happy!!" << endl;
	else cout << "I'm unhappy!!" << endl;
}
