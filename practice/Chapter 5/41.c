#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int c);

int g_nTokenType;
char g_szToken[MAXTOKEN];
char g_szName[MAXTOKEN];
char g_szDataType[MAXTOKEN];
char g_szOut[MAXTOKEN];

int main()
{
	while (gettoken() != EOF)
	{
		strcpy(g_szDataType, g_szToken);
		g_szOut[0] = '\0';
		dcl();
		if (g_nTokenType != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", g_szName, g_szOut, g_szDataType);
	}

	return 0;
}

void dcl(void)
{
	int ns = 0;

	for (ns = 0; gettoken() == '*';)
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(g_szOut, " pointer to");
}

void dirdcl(void)
{
	int type = 0;

	if (g_nTokenType == '(')
	{
		dcl();
		if (g_nTokenType != ')')
			printf("error: missing )\n");
	}
	else if (g_nTokenType == NAME)
		strcpy(g_szName, g_szToken);
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type== PARENS)
			strcat(g_szOut, " function returning");
		else
		{
			strcat(g_szOut, " array");
			strcat(g_szOut, g_szToken);
			strcat(g_szOut, " of");
		}
}

int gettoken(void)
{
	int c = 0;
	char *p = g_szToken;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		if ((c = getch()) == ')')
		{
			strcpy(g_szToken, "()");
			return g_nTokenType = PARENS;
		}
		else
		{
			ungetch(c);
			return g_nTokenType = '(';
		}
	}
	else if (c == '[')
	{
		for (*p++ = c; (*p++ = getch()) != ']';)
			;
		*p = '\0';
		return g_nTokenType = BRACKETS;
	}
	else if (isalpha(c))
	{
		for (*p++ = c; isalnum(c = getch());)
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return g_nTokenType = NAME;
	}
	else
		return g_nTokenType = c;
}

#define BUFSIZE 100

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
