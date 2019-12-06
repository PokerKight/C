#include <stdio.h>

int main()
{
	float fahr = 0;
	float celsius = 0.0;
	int lower = 0;
	int upper = 300;
	int step = 20;
	
	fahr = lower;
	printf("Fahr  Celsius\n");
	while (fahr <= upper)
	{
		celsius = 5.0 * (fahr - 32.0) / 9.0;
		printf("%3.0f  %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}

