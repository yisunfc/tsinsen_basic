#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool check_wrong(const string& a, const string &b)
{
	int mis = 0;
	int length_minus = (int)a.size() - (int)b.size();
	size_t i = 0, j = 0;
	for ( ; i < a.size() && j < b.size(); )
	{
		if (a[i] == b[j]) ++i, ++j;
		else
		{
			if (length_minus < 0) ++j;
			else if (length_minus > 0) ++i;
			else ++i, ++j;
			++mis;
		}
	}
	if (i < a.size()) mis += (a.size() - i);
	if (j < b.size()) mis += (b.size() - j);
	return mis <= 1;
}
string familiar_word(const string &word, const vector<string> &dict)
{
	for (auto const &w : dict) if (check_wrong(word, w)) return w;
	return "NOANSWER";
}

int main()
{
	string word, temp;
	vector<string> dict;
	cin >> word;
	int size;
	cin >> size;
	while (size--)
	{
		cin >> temp;
		dict.push_back(temp);
	}
	for (auto const &w : dict)
		if (w == word)
		{
			cout << word << endl;
			return 0;
		}
	cout << familiar_word(word, dict) << endl;
	return 0;
}
