#include <cstdio>

char out[] = "0123456789ABCDEF";

int main()
{
	int num;
	scanf("%d", &num);
	char i = out[num / 16];
	char j = out[num % 16];
	printf("%c%c\n", i, j);
	return 0;
}
