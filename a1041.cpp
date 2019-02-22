#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Matrix
{
	Matrix(int _n)
	{
		n = _n;
	}
	Matrix(const Matrix& m)
	{
		n = m.n;
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < n; ++j)
				data[i][j] = m.get(i, j);
	}
	long long get(int i, int j) const
	{
		return data[i][j];
	}
	void set(int i, int j, long long d)
	{
		data[i][j] = d;
	}
	void output(ostream& os) const
	{
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (j != n - 1) os << get(i, j) << ' ';
				else os << get(i, j);
			}
			cout << endl;
		}
	}
	void normalize()
	{
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < n; ++j)
			{
				if (i == j) set(i, j , 1);
				else set(i, j, 0);
			}
	}

	int n;
	long long data[30][30];
};

void power(Matrix& m1, int p)
{
	if (p == 0)
		return m1.normalize();

	Matrix m2(m1);
	while (--p)
	{
		Matrix temp(m1.n);
		for (int i = 0; i < m1.n; ++i)
		{
			for (int j = 0; j < m1.n; ++j)
			{
				long long sum = 0;
				for (int k = 0; k < m1.n; ++k)
					sum += m1.get(i, k) * m2.get(k, j);
				temp.set(i, j, sum);
			}
		}
		m1 = temp;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int r = 0, c = 0;
	Matrix mt(n);
	while (r < n)
	{
		long long i;
		cin >> i;
		mt.set(r, c, i);
		if (++c == n) c = 0, ++r;
	}

	power(mt, m);
	mt.output(cout);

	return 0;
}
