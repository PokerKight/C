#include <stdio.h>

#define LOWER 1
#define UPPER 301
#define STEP  20

int main()
{
	int celsius = 0;
	
	printf("Celsius  Fahr\n");
	for (celsius = UPPER; celsius >= LOWER; celsius -= STEP)
	{
		printf("%6d  %6.1f\n", celsius, 9.0*celsius/5.0 + 32);
		
	}
	
	return 0;
}

