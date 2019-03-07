#include <iostream>
using namespace std;

int classrooms[] = {120,40,85,50,100,140,70,100};

int main()
{
	int na, nb, nc, nd;
	cin >> na >> nb >> nc >> nd;
	bool no = true;
	for (int a = 0; a < 8; ++a)
		for (int b = 0; b < 8; ++b)
			for (int c = 0; c < 8; ++c)
				for (int d = 0; d < 8; ++d)
				{
					if (a != b && a != c && a != d && b != c && b != d && c != d && na <= classrooms[a] && nb <= classrooms[b] && nc <= classrooms[c] && nd <= classrooms[d])
					{
						cout << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << d+1 << endl;
						no = false;
					}
				}
	if (no)
		cout << -1 << endl;
	return 0;
}
