#include <iostream>
#include <deque>

using namespace std;
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef deque<char> CVEC;

void output(const CVEC &vec)
{
	for (auto c : vec)
		cout << c;
	cout << endl;
}

void show_figure(int row, int column)
{
	CVEC cvec(alphabet, alphabet + column);
	while (row-- > 0)
	{
		output(cvec);
		cvec.pop_back();
		cvec.push_front(cvec.front() + 1);
	}
}

int main()
{
	show_figure(25, 18);
	return 0;
}
