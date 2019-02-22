#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int HEX_UNIT = 3;

int from_char(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return 0;
}

void output(const char* str, int size, bool first)
{
	char temp[13] = {'\0'};
	for (int i = 0; i < 12; ++i) temp[i] = '0';
	int pos = (HEX_UNIT - size) * 4;
	for (int i = 0; i < size; ++i, pos += 4)
	{
		int n = from_char(str[i]);
		if (n >= 8) temp[pos+0] = '1';
		if (n % 8 >= 4) temp[pos+1] = '1';
		if (n % 4 >= 2) temp[pos+2] = '1';
		if (n % 2) temp[pos+3] = '1';
	}

	for (int i = 0; i < 4; ++i)
	{
		int pow = 4, num = 0;
		int index = i * 3;
		for (int j = index; j < index + 3; ++j)
		{
			if (temp[j] == '1') num += pow;
			pow /= 2;
		}
		if (num != 0 && first) first = false;
		if (num != 0 || !first) cout << num;
	}
}

int main()
{
	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		string str;
		cin >> str;
		int pos = str.size() % HEX_UNIT;
		bool first = true;
		if (pos)
		{
			output(str.c_str(), pos, first);
			first = false;
		}

		while (pos < str.size())
		{
			output(str.c_str() + pos, HEX_UNIT, first);
			if (first) first = false;
			pos += HEX_UNIT;
		}
		cout << endl;
	}

	return 0;
}
