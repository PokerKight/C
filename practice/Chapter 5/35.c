#include <stdio.h>

int atoi(char *s)
{
	int n = 0;
	int sign = 0;

	while (*s == ' ')
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	
	while (*s >= '0' && *s <= '9')
		n = 10 * n + *s++ - '0';
	
	return sign * n;
}

int main()
{
	char s[256] = {0};
	int n = 0;
	
	scanf("%s", s);
	n = atoi(s);
	printf("%d\n", n);

	return 0;
}