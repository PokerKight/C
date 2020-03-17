#include <stdio.h>

int strindex(char *s, char *t)
{
	char *psStart = s;
	char *ps = NULL;
	char *pt = NULL;

	for (; *s != '\0'; s++)
	{
		for (ps = s, pt = t; *pt != '\0' && *ps == *pt; ps++, pt++)
			;
		if (pt > t && *pt == '\0')
			return s - psStart;
	}

	return -1;
}

int main()
{
	char s[256] = {0};
	char t[256] = {0};
	int ret = 0;

	scanf("%s", s);
	scanf("%s", t);
	ret = strindex(s, t);
	printf("%d\n", ret);
	
	return 0;
}