#include <stdio.h>

#define MAX_LINE_LEN	1000
#define EMPTY_LINE	0	

int getLine(char szLine[], int nMaxLineLen);
void reverse(char szLine[]);

int main()
{
	char szLine[MAX_LINE_LEN];

	while (getLine(szLine, MAX_LINE_LEN) > EMPTY_LINE)
	{
		reverse(szLine);
		printf("%s\n", szLine);
	}

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