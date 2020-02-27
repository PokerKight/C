#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

#ifdef POINT
void reverse(char *szLine)
{
	char *pEnd = NULL;
	char temp = 0;

	pEnd = szLine + (strlen(szLine)-1);
	while (szLine <= pEnd)
	{
		temp = *szLine;
		*szLine++ = *pEnd;
		*pEnd-- = temp;
	}
}

void itoa(int n, char *s)
{
	int sign = 0;
	char *t = s;
	
	sign = n;
	do {
		*s++ = abs(n % 10) + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(t);
}
#else
void reverse(char szLine[])
{
	int i = 0;
	int j = 0;
	char temp = 0;

	j = strlen(szLine)-1;
	while (i <= j)
	{
		temp = szLine[i];
		szLine[i++] = szLine[j];
		szLine[j--] = temp;
	}
}

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
#endif

int main()
{
	int n = 0;
	char s[256] = {0};

	scanf("%d", &n);
	itoa(n, s);
	printf("%s\n", s);

	return 0;
}
