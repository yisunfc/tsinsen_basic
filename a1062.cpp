#include <iostream>

using namespace std;

int main()
{
	int v1, v2, s, t, l;
	cin >> v1 >> v2 >> s >> t >> l;
	int dis_1 = 0, dis_2 = 0, time = 0, next = 1;
	while (true)
	{
		++time;
		if (dis_1 - dis_2 >= s && next == time)
			next = time + t;
		if (next == time)
		{
			dis_1 += v1; next = time + 1;
		}
		dis_2 += v2;

		if (dis_2 >= l || dis_1 >= l) break;
	}
	if (dis_2 > dis_1) cout << "T" << endl;
	else if (dis_2 == dis_1) cout << "D" << endl;
	else cout << "R" << endl;
	cout << time << endl;
	return 0;
}
