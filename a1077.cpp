#include <iostream>
using namespace std;
struct position {
	int x;
	int y;
};
void psort(position ps[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (ps[min].x > ps[j].x || (ps[min].x == ps[j].x && ps[min].y > ps[j].y))
				min = j;
		}
		if (min != i)
			swap(ps[i], ps[min]);
	}
}
const int maxn = 100;
position points[maxn];
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y;
	psort(points, n);
	for (int i = 0; i < n; ++i)
		cout << points[i].x << " " << points[i].y << endl;
	return 0;
}
