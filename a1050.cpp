#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string dna;
	size_t cnt = 0;
	cin >> dna;
	for (auto c : dna) if (c == 'G' || c == 'C') ++cnt;
	cout << round((double)cnt * 100 / dna.size()) << endl;
	return 0;
}
