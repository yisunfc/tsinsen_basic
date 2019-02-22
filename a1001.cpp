#include <cstdio>

void str_plus(char* str)
{
	int idx = 5;
	while (idx >= 0)
	{
		if (str[idx] == '0')
		{
			str[idx] = '1';
			while (++idx <= 5)
			{
				str[idx] = '0';
			}
			return;
		}
		else
			idx--;
	}
}

int main()
{
	char str[7] = "000000";
	for (int i = 0; i < 64; ++i)
	{
		printf("%s\n", str);
		str_plus(str);
	}
	return 0;
}
