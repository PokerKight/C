#include <stdio.h>

#define TABINC	8

int main()
{
	int c = 0;
	int nBlankNum = 0;
	int nPosition = 1;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			nBlankNum = TABINC - (nPosition - 1) % TABINC;
			while (nBlankNum > 0)
			{
				putchar(' ');
				++nPosition;
				--nBlankNum;
			}
		}
		else if (c == '\n')
		{
			putchar(c);
			nPosition = 1;
		}
		else
		{
			putchar(c);
			++nPosition;
		}
	}
}