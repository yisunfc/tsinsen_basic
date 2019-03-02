#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	string text;
	cin >> text;
	int m;
	cin >> m;
	if (m == 0 || m > text.size())
		return 0;
	multiset<string> ans;
	for (size_t i = 0; i <= text.size() - m; ++i)
	{
		ans.insert(text.substr(i, m));
	}
	size_t cnt = 0;
	for (auto const &str : ans)
	{
		cout << str;
		if (++cnt != ans.size())
			cout << ' ';
	}
	if (!ans.empty())
		cout << endl;
	return 0;
}

