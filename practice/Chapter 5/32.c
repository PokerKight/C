#include <stdio.h>

void my_strcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

int main()
{
	char s[256] = {0};
	char t[256] = {0};
	char r[256] = {0};

	scanf("%s", s);
	scanf("%s", t);
	scanf("%s", r);

	my_strcat(s, t);
	my_strcat(s, r);
	printf("%s\n", s);
		
	return 0;
}
