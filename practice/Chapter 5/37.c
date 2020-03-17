#include <stdio.h>
#include <string.h>

/*
int strrindex(char *s, char *t)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int pos = -1;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}

int strrindex(char *s, char *t)
{
	char *psStart = s;
	char *ps = NULL;
	char *pt = NULL;
	int pos = -1;

	for (; *s != '\0'; s++)
	{
		for (ps = s, pt = t; *pt != '\0' && *ps == *pt; ps++, pt++)
			;
		if (pt > t && *pt == '\0')
			pos = s - psStart;
	}
	return pos;
}

int strrindex(char *s, char *t)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = strlen(s) - strlen(t); i >= 0; i--)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
*/

int strrindex(char *s, char *t)
{
	char *psStart = s;
	char *ps = NULL;
	char *pt = NULL;

	for (s = psStart + strlen(s) - strlen(t); s >= psStart; s--)
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
	ret = strrindex(s, t);
	printf("%d\n", ret);
	
	return 0;
}