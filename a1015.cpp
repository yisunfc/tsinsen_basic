#include <iostream>
#include <vector>

using namespace std;

int main()
{
	typedef vector<long long> IVEC;
	int scale;
	cin >> scale;
	vector<IVEC> triangle;
	IVEC first{1};
	triangle.push_back(first);
	for (int i = 1; i < scale; ++i)
	{
		const IVEC &last_row = triangle[i - 1];
		IVEC cur_row{1};
		for (int j = 1; j < i + 1; ++j)
		{
			if (j >= last_row.size()) cur_row.push_back(1);
			else cur_row.push_back(last_row[j] + last_row[j - 1]);
		}
		triangle.push_back(cur_row);
	}

	for (const auto& vec : triangle)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			if (i != vec.size() - 1)
				cout << vec[i] << ' ';
			else
				cout << vec[i];
		}
		cout << endl;
	}
}


