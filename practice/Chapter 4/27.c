#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP	100
#define NUMBER	'0'
#define NAME	'n'

int getop(char s[]);
void push(double f);
double pop(void);
void mathfnc(char s[]);

int main()
{
	int type = 0;
	double op2 = 0.0;
	char s[MAXOP] = {0};

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case NAME:
				mathfnc(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

#define MAXVAL	100

int sp = 0;
double val[MAXVAL] = {0};

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can;t push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

void mathfnc(char s[])
{
	double op2;

	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0)
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("error %s not supported\n", s);
}

#include <ctype.h>

int getch(void);
void ungetch(int c);

#ifdef POINT
int getop(char *s)
{
	int c = 0;

	while ((*s = c = getch()) == ' ' || c == '\t')
		;
	*(s+1) = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	if (isdigit(c))
		while (isdigit(*++s = c = getchar()))
			;
	if (c == '.')
		while (isdigit(*++s = c = getchar()))
			;
	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
#else
int getop(char s[])
{
	int i = 0;
	int c = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (islower(c))
	{
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (strlen(s) > 1)
			return NAME;
		else
			return c;
	}
	if (!isdigit(c) && c != '.')
		return c;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
#endif

#define BUFSIZE	100

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

