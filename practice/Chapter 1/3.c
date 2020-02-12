#include <stdio.h>

#define LOWER 1
#define UPPER 301
#define STEP  20

int main()
{
	int nCelsius = 0;
	
	printf("Celsius  Fahr\n");
	for (nCelsius = UPPER; nCelsius >= LOWER; nCelsius -= STEP)
	{
		printf("%6d  %6.1f\n", nCelsius, 9.0*nCelsius/5.0 + 32);
	}
	
	return 0;
}
