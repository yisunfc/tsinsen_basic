#include <iostream>

using namespace std;

int main()
{
	int N, b[26] = {0}, odd = 0;
	char s[8001] = {0}, charodd = '0';
	cin >> N >> s;
	for (int i = 0; i < N; i++) b[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		if (b[i] % 2 == 1)
		{
			odd++;
			charodd = i + 'a';
		}
	if (odd > 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	int change = 0;
	for (int i = 0; i < N/2; i++)
	{
		if (s[i] == charodd)
		{
			int j = 0;
			for (j = i; j <= N-i-1; j++)
				if (s[j] == s[N-i-1])
					break;
			change += j - i;
			for (int k = j; k > i; k--)
				s[k] = s[k-1];
			s[i] = s[N-i-1];
		}
		else
		{
			int j = 0;
			for (j = N-i-1; j >= i; j--) if (s[j] == s[i]) break;
			change += N-i-1 - j;
			for (int k = j; k < N-i-1; k++) s[k] = s[k+1];
			s[N-i-1] = s[i];
		}
		cout << s << endl;
	}
	cout << change << endl;
	return 0;
}
