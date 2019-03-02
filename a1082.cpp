#include <iostream>

using namespace std;

int findKth(int *s, int n, int K)
{
	int pivot = s[0];
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (s[j] > pivot && i < j) 
			--j;
		if (i < j)
			s[i++] = s[j];
		while (s[i] < pivot && i < j)
			++i;
		if (i < j)
			s[j--] = s[i];
	}
	s[i] = pivot;
	if (i == K - 1)
		return s[i];
	else if (i >= K)
		return findKth(s, i, K);
	else
		return findKth(s + i + 1, n - i - 1, K - i - 1);
}


int main()
{
	int a[] = {1,2,3,4,5};
	int b = findKth(a, 5, 1);
	cout << b << endl;
	return 0;
}
