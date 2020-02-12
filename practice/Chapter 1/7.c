#include <stdio.h>

#define IN	1
#define OUT	0

int main()
{
	int c = 0;
	int nState = 0;
	
	nState = OUT;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (nState == IN)
			{
				putchar('\n');
				nState = OUT;
			}
		}
		else if (nState == OUT)
		{
			putchar(c);
			nState = IN;
		}
		else
			putchar(c);
	}
	
	return 0;
}
