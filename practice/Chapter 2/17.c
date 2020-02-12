#include <stdio.h>

#define MAXLINE 80
#define YES 1
#define NO	0

int getLine(char szLine[], int nMaxLine);
int htoi(char s []);

int main()
{
	int nLen = 0;
	char szLine[MAXLINE] = {0};
	
	if (getLine(szLine, MAXLINE) > 0)
		printf("%d\n", htoi(szLine));

	return 0;
}

int getLine(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

int htoi(char s[])
{
	int hexdigit, i, inhex, n;

	i = 0;
	if (s[i] == '0')
	{
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	n = 0;
	inhex = YES;
	for (; inhex == YES; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	
	return n;
}

