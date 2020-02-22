#include <stdio.h>
#include <ctype.h>

#define BUFSIZE	100
#define SIZE	8

char buf[BUFSIZE] = {0};
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getfloat(float *pn)
{
	int c = 0;
	int sign = 0;
	float power;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0.0; isdigit(c); c=getch())
		*pn = 10.0*(*pn) + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch())
	{
		*pn = 10.0*(*pn) + (c - '0');
		power *= 10.0;
	}
	*pn *= sign / power;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main()
{
	int n = 0;
	float array[SIZE] = {0};

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	for (n = 0; n < SIZE; n++)
		printf("%f ", array[n]);
	printf("\n");

	return 0;
}
