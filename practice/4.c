#include <stdio.h>

int main()
{
	int c = 0;
	
	while ((c = getchar()) != EOF)
	{
		printf("%c is not EOF\n", c);
		return 0;
	}
	
	printf("EOF is %d\n", EOF);
	
	return 0;
}

