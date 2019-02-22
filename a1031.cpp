#include <iostream>
#include <deque>

using namespace std;

char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void draw(int n)
{
	deque<char> q;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
			q.push_back(letter[i]);
		else
		{
			q.push_front(letter[i]);
			q.push_back(letter[i]);
		}
		for (auto c : q)
			cout << c;
		cout << endl;
	}
}

int main()
{
	draw(15);
	return 0;
}
