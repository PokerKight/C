#include <stdio.h>

#define MAX_LINE_LEN	1000
#define EMPTY_LINE	0

int getLine(char szLine[], int nMaxLineLen);
int reMove(char szLine[]);

int main()
{
	char szLine[MAX_LINE_LEN];

	while (getLine(szLine, MAX_LINE_LEN) > EMPTY_LINE)
		if (reMove(szLine) > EMPTY_LINE)
			printf("%s\n", szLine);

	return 0;
}

int getLine(char szLine [], int nMaxLineLen)
{
	int c = 0;
	int i = 0;

	for (i = 0; i < MAX_LINE_LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		szLine[i] = c;
	if (c == '\n')
	{
		szLine[i] = c;
		++i;
	}
	szLine[i] = '\0';
	
	return i;
}

int reMove(char szLine[])
{
	int i = 0;

	while (szLine[i] != '\n' && szLine[i] != '\0')
		++i;

	if (szLine[i] == '\n')
		--i;
	else
		--i;
	
	while (i >= 0 && (szLine[i] == ' ' || szLine[i] == '\t'))
		--i;
	
	if (i > 0)
	{
		++i;
		szLine[i] = '\0';
	}
	
	return i;
}

