#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string last, name;
	cin >> last;
	set<string> names;
	while (n--)
	{
		cin >> name;
		names.insert(name);
	}
	auto it = names.find(last);
	if (++it == names.end())
		cout << "The End" << endl;
	else 
		cout << *it << endl;
}
