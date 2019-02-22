#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	vector<int> vec;
	cin >> n;
	while (n--)
	{
		double x, y;
		cin >> x >> y;
		vec.push_back((x * x + y * y) *3.1415926 / 100 + 1);
	}
	for (auto i : vec) 
		cout << i << endl;

	return 0;
}

