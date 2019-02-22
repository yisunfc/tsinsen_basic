#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n;
	vector<int> ivec;
	while (n--)
	{
		int i;
		cin >> i;
		ivec.push_back(i);
	}
	cin >> k;
	for (int i = 0; i < ivec.size(); ++i)
	{
		if (ivec[i] == k) 
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}
