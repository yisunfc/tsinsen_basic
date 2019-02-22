#include <iostream>

using namespace std;

char letters[] = {'A', 'B', 'C', 'D'};

int main()
{
	int cnt = sizeof(letters) / sizeof(char);
	for (int a = 0; a < cnt; ++a)
		for (int b = 0; b < cnt; ++b)
			for (int c = 0; c < cnt; ++c)
				for (int d = 0; d < cnt; ++d)
					cout << letters[a] << letters[b] << letters[c] << letters[d] << endl;

	return 0;
}
