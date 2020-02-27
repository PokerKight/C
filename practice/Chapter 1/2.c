#include <stdio.h>

int main()
{
	float nFahr = 0.0;
	float nCelsius = 0.0;
	int nLower = 0;
	int nUpper = 300;
	int nStep = 20;
	
	nFahr = nLower;
	printf("Fahr  Celsius\n");
	while (nFahr <= nUpper)
	{
		nCelsius = 5.0 * (nFahr - 32.0) / 9.0;
		printf("%3.0f  %6.1f\n", nFahr, nCelsius);
		nFahr = nFahr + nStep;
	}
	
	return 0;
}
