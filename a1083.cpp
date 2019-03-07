#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
struct SortIndex
{
	SortIndex() : index(100) {}
	int index;
	int row;
	bool operator<(const SortIndex &r) const
	{
		return index < r.index || row < r.row;
	}
};
SortIndex non0[10];
double a[10][11], t[10][11], b[10]; 
int n;

bool iszero(double x)
{
	return abs(x) < 0.00000001;
}
int find_nonzero(int i, int pos = 0)
{
	for (int j = pos; j < n; ++j) 
		if (!iszero(a[i][j])) 
			return j;
	return 10;
}
void sort_matrix()
{
	for (int i = 0; i < n; ++i)
	{
		non0[i].row = i;
		for (int j = 0; j < n; ++j)
			if (a[i][j])
			{
				non0[i].index = j;
				break;
			}
	}

	sort(non0, non0 + n);
	for (int i = 0; i < n; ++i)
	{
		int row = non0[i].row;
		for (int j = 0; j <= n; ++j) 
			t[i][j] = a[row][j];
	}

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j <= n; ++j) 
			a[i][j] = t[i][j];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			cin >> a[i][j];
	for (int i = 0; i < n; ++i) 
		cin >> a[i][n];
	sort_matrix();

	for (int i = 0; i < n - 1; ++i)
	{
		int index = find_nonzero(i);
		for (int i2 = i + 1; i2 < n; ++i2)
		{
			if (find_nonzero(i2) > index) continue;
			double k = a[i2][index] / a[i][index];
			for (int j = index; j <= n; ++j)
				a[i2][j] -= k * a[i][j];
		}
		sort_matrix();
	}
	for (int i = n - 1; i >=0; --i)
	{
		b[i] = a[i][n];
		for (int j = i + 1; j < n; ++j)
		{
			b[i] -= a[i][j] * b[j];
		}
		if (!iszero(a[i][i]))
			b[i] /= a[i][i];
	}
	for (int i = 0; i < n; ++i) 
	{
		printf("%.2f\n", b[i]);
	}
	return 0;
}
