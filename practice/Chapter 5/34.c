#include <stdio.h>
#include <string.h>

void my_strncpy(char *s, char *t, int n)
{
	while (*t && n-- > 0)
		*s++ = *t++;
	while (n-- > 0)
		*s++ = '\0';
}

void my_strncat(char *s, char *t, int n)
{
	my_strncpy(s+strlen(s), t, n);
}

int my_strncmp(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;
}

int main()
{
	char s[256] = {0};
	char t[256] = {0};
	int n = 0;
	int ret = 0;

	scanf("%s", s);
	scanf("%s", t);
	
	ret = my_strncmp(s, t, strlen(t));
	if (ret > 0)
		printf("s > t\n");
	else if (ret < 0)
		printf("s < t\n");
	else
		printf("s == t\n");

	my_strncat(s, t, strlen(t));
	printf("%s\n", s);

	n = strlen(s) - strlen(t);
	my_strncat(t, s + strlen(t), n);
	printf("%s\n", t);

	my_strncpy(t, s, strlen(s) - n);
	printf("%s\n", t);

	ret = my_strncmp(s, t, strlen(s));
	if (ret > 0)
		printf("s > t\n");
	else if (ret < 0)
		printf("s < t\n");
	else
		printf("s == t\n");
	
	return 0;
}
