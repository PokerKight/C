#include <stdio.h>

void reverse(char szLine[])
{
	int i = 0;
	int j = 0;
	char temp = 0;

	while (szLine[i] != '\0')
		++i;
	--i;
	if (szLine[i] == '\n')
		--i;

	j = 0;
	while (j < i)
	{
		temp = szLine[j];
		szLine[j] = szLine[i];
		szLine[i] = temp;
		--i;
		++j;
	}

	return;
}

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[])
{
	int i = 0;
	int sign = 0;

	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	
	int n = 0;
	char s[256] = {0};

	scanf("%d", &n);
	itoa(n, s);
	printf("%s\n", s);

	return 0;
}
