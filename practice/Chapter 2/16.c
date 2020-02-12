#include <stdio.h>

#define MAX_LIMIT 10

int main()
{
	enum loopFlag {NO, YES};
	enum loopFlag isLoop = YES;
	int c = 0;
	int i = 0;
	
	while (isLoop == YES)
	{
		if ( i >= MAX_LIMIT)
			isLoop = NO;
		else if ((c = getchar()) == 'r')
			isLoop = NO;
		else if (c == EOF)
			isLoop = NO;
		else
		{
			printf("%c", c);
			++i;
		}
	}
	
	return 0;
}
