#include <stdio.h>

int wordlength(void)
{
	int i = 0;
	unsigned char v = (unsigned char) ~0;

	for (i = 1; (v = v >> 1) > 0; i++)
		;

	return i;  
}

unsigned int rightrot(unsigned x, int n)
{
	unsigned char rbit = 0;
	int len = 0;

	len = wordlength();

	while (n-- > 0)
	{
		rbit = (x & 1) << (len - 1);
		x = x >> 1;
		x = x | rbit;
	}

	return x;
}


int main()
{
	unsigned int x = 0;
	int n = 0;
	unsigned int ret = 0;
	
	scanf("%u %d", &x, &n);
	ret = rightrot(x, n);
	
	printf("%d\n", ret);
	
	return 0;
}
