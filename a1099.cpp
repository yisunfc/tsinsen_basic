#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n = 8;
struct Words
{
	int yes; int no;
};

string weekdays[] = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};
string output[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int convert(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (int i = 0; i < 7; ++i)
	{
		if (str == weekdays[i])
			return i+1;
	}

	return -1;
}
void check(vector<Words>& vw)
{
	for (int day = 1; day < 8; ++day)
	{
		int cnt = 0;
		for (auto const &w : vw)
		{
			if (!((w.yes == day && w.no == day) || (w.yes != day && w.no != day)))
				break;
			++cnt;
		}
		if (cnt == 8)
		{
			cout << output[day] << endl;
			return;
		}
	}
}

int main()
{
	int index = 0;
	string day1, day2;
	Words w;
	vector<Words> vw;
	for (int i = 0; i < n; ++i)
	{
		cin >> day1 >> day2;
		w.yes = convert(day1);
		w.no = convert(day2);
		vw.push_back(w);
	}

	check(vw);
	return 0;
}
