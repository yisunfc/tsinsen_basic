#include <iostream>

using namespace std;

int main()
{
	int time;
	cin >> time;
	int hour = time / 3600;
	int min = (time % 3600) / 60;
	int sec = time % 60;
	cout << hour << ":" << min << ":" << sec << endl;

	return 0;
}
