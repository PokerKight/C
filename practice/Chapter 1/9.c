#include <stdio.h>

#define MAX_LINE_LEN	1000	
#define EMPTY_LINE		0		
#define LIMIT_LINE_LEN	81

#ifdef POINT
int getLine(char *szLine, int nLen)
{
	int c = 0;
	char *pStart = szLine;

	while (--nLen > 0 && (c = getchar()) != EOF && c != '\n')
		*szLine++ = c;
	if (c == '\n')
		*szLine++ = c;
	*szLine = '\0';
	return szLine - pStart;
}
#else
int getLine(char szLine[], int nLen)
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
#endif

int main()
{
	int nLineLen;
	char szLine[MAX_LINE_LEN];

	while ((nLineLen = getLine(szLine, MAX_LINE_LEN)) > EMPTY_LINE)
		if (nLineLen > LIMIT_LINE_LEN)
			printf("%s", szLine);
		
	return 0;
}