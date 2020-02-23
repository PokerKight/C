#include <stdio.h>

int strend(char *s, char *t)
{
	char *psStart = s;
	char *ptStart = t;
	
	while (*s)
		s++;
	while (*t)
		t++;
	while (*s-- == *t--)
	{
		if (t == ptStart)
			return 1;
		if (s == psStart)
			break;
	}

	return 0;
}

int main()
{
	char s[256] = {0};
	char t[256] = {0};

	fgets(s, 255, stdin);
	fgets(t, 255, stdin);

	if (strend(s, t))
		printf("in\n");
	else
		printf("out\n");
		
	return 0;
}
