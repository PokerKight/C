#include <stdio.h>

int main()
{
	int c = 0;
	int nBlankNum = 0;
	int nTabNum = 0;
	int nLineNum = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++nBlankNum;
		else if (c == '\t')
			++nTabNum;
		else if (c == '\n')
			++nLineNum;
	}
		
	printf("%d %d %d", nBlankNum, nTabNum, nLineNum);
	
	return 0;
}
