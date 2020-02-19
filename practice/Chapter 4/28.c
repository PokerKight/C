#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[])
{
	static int i = 0;

	if (n / 10)
		itoa(n/10, s);
	else
	{
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n%10) + '0';
	s[i] = '\0';
}

int main()
{
	int n = 0;
	char s[256] = {0};

	scanf("%d", &n);
	itoa(n, s);
	printf("%s\n", s);
}
