#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int cnt;
	cin >> cnt;
	vector<int> ivec;
	while (cnt--)
	{
		int i;
		cin >> i;
		ivec.push_back(i);
	}
	sort(ivec.begin(), ivec.end());
	for (size_t i = 0; i < ivec.size(); ++i)
	{
		cout << ivec[i];
		if (i != ivec.size() - 1) cout << ' ';
	}
	cout << endl;

	return 0;
}
