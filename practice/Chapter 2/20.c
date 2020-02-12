#include <stdio.h>

unsigned char setbits(unsigned char x, int p, int n, unsigned char y)
{
	return x & ~(~(~0 << n) << (p+1-n)) |
		   (y & ~(~0 << n) << (p+1-n));
}

int main()
{
	unsigned int x = 0;
	unsigned int y = 0;
	int p = 0;
	int n = 0;
	unsigned ret = 0;
	
	scanf("%u %u %d %d", &x, &y, &p, &n);
	ret = setbits(x, p, n, y);
	
	printf("%d\n", ret);
	
	return 0;
}
