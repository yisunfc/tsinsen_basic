#include <iostream>
#include <string>

using namespace std;

int main()
{
	string text;
	cin >> text;
	int max = 0;
	for (int i = 0; i < text.size(); ++i)
	{
		for (int j = i + 1; j < text.size(); ++j)
		{
			int L = j - i + 1;
			if (L % 2) continue;
			int l = L / 2;
			if (text.substr(i, l) != text.substr(i+l, l)) continue;
			if (L > max) max = L;
		}
	}

	cout << max << endl;
	return 0;
}
