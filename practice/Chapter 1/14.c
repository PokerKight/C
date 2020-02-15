#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

int main()
{
	int c = 0;

	while ((c = getchar()) != EOF)
		rcomment(c);

	return 0;
}

void rcomment(int c)
{
	int temp = 0;

	if (c == '/')
	{
		if ((temp = getchar()) == '*')
			in_comment();
		else if (temp == '/')
		{
			putchar(c);
			rcomment(temp);
		}
		else
		{
			putchar(c);
			putchar(temp);
		}
	} else if (c == '\'' || c == '"')
		echo_quote(c);
	else
		putchar(c);
}

void in_comment(void)
{
	int c = 0;
	int temp = 0;

	c = getchar();
	temp = getchar();

	while (c != '*' || temp != '/')
	{
		c = temp;
		temp = getchar();
	}
}

void echo_quote(int c)
{
	int temp = 0;

	putchar(c);
	while ((temp = getchar()) != c)
	{
		putchar(temp);
		if (temp == '\\')
			putchar(getchar());
	}
	putchar(temp);
}