#include <stdio.h>

#define swap(t, x, y) \
	{	t _z;		  \
		_z = y; 	  \
		y = x;  	  \
		x = _z;}
	

int main()
{
	int x = 0;
	int y = 0;

	scanf("%d %d", &x, &y);
	swap(int, x, y);
	printf("x = %3d, y = %3d\n", x, y);
	swap(char, x, y);
	printf("x = %3c, y = %3c\n", x, y);

	return 0;
}
