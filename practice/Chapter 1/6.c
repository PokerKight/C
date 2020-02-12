#include <stdio.h>

#define NONBLANK 'a'

int main()
{
	int c = 0;
	int nLastC = 0;
	
	nLastC = NONBLANK;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (nLastC != ' ')
				putchar(c);
		nLastC = c;
	}
	
	return 0;
}
