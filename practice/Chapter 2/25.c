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

void itob(int n, char s[], int b)
{
	int i = 0;
	int j = 0;
	int sign = 0;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		j = n % b;
		s[i++] = (j <= 9) ? j + '0' : j + 'A' - 10;
	} while ((n /= b) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	int n = 0;
	char s[256] = {0};
	int b = 0;

	scanf("%d", &n);
	scanf("%d", &b);
	itob(n, s, b);
	printf("%s\n", s);

	return 0;
}