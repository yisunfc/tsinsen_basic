#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt[26] = {0};
	string str;
	cin >> str;
	for (auto c : str)
		cnt[c - 'a']++;
	for (int i = 0; i < 26; ++i)
		if (cnt[i] > 0) cout << char('a' + i) << " " << cnt[i] << endl;

	return 0;
}
