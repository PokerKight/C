#include <stdio.h>

unsigned char invert(unsigned char x, int p, int n)
{
	return 	x ^ (~(~0 << n) << (p+1-n));
}

int main()
{
	unsigned int x = 0;
	int p = 0;
	int n = 0;
	unsigned ret = 0;
	
	scanf("%u %d %d", &x, &p, &n);
	ret = invert(x, p, n);
	
	printf("%d\n", ret);
	
	return 0;
}
