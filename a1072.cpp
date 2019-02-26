#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	string text, code, str;
	set<char> check;
	char pwd[26] = {0};
	cin >> text >> code >> str;
	if (code.size() < 26)
	{
		cout << "Failed" << endl; return 0;
	}
	for (size_t i = 0; i < text.size(); ++i)
	{
		int index = text[i] - 'A';
		if (pwd[index] && pwd[index] != code[i])
		{
			cout << "Failed" << endl; return 0;
		}
		else
			pwd[index] = code[i];
	}
	for (size_t i = 0; i < 26; ++i)
		check.insert(pwd[i]);
	if (check.size() != 26)
	{
		cout << "Failed" << endl; return 0;
	}
	for (size_t i = 0; i < str.size(); ++i)
	{
		int index = str[i] - 'A';
		if (pwd[index]) str[i] = pwd[index];
		else
		{
			cout << "Failed" << endl; return 0;
		}
	}
	cout << str << endl;
	return 0;
}

