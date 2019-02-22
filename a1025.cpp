#include <iostream>
#include <string>

using namespace std;

int compare(const string& a, const string& b)
{
	if (a.size() != b.size()) return 1;
	if (a == b) return 2;
	for (size_t i = 0; i < a.size(); ++i)
	{
		if (toupper(a[i]) != toupper(b[i]))
			return 4;
	}
	return 3;
}

int main()
{
	string a, b;
	cin >> a >> b;

	cout << compare(a, b) << endl;
	return 0;
}
