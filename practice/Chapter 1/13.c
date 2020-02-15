 #include <stdio.h>

#define MAXCOL	10

char g_szLine[MAXCOL] = {0};

int find_blank(int nPosition);
int new_position(int nPosition);
void printl(int nPosition);

int main()
{
	int c = 0;
	int nPosition = 0;

	while ((c = getchar()) != EOF)
	{
		g_szLine[nPosition] = c;
		if (c == '\n')
		{
			printl(nPosition);
			nPosition = 0;
		}
		else if (++nPosition >= MAXCOL)
		{
			nPosition = find_blank(nPosition);
			printl(nPosition);
			nPosition = new_position(nPosition);
		}
	}

	return 0;
}

void printl(int nPosition)
{
	int i = 0;
	
	for (i = 0; i < nPosition; i++)
		putchar(g_szLine[i]);
	if (nPosition > 0)
		putchar('\n');
}

int find_blank(int nPosition)
{
	while (nPosition > 0 && g_szLine[nPosition] != ' ')
		--nPosition;
	if (nPosition == 0)
		return MAXCOL;
	else
		return nPosition+1;
}

int new_position(int nPosition)
{
	int i = 0;
	int j = 0;

	if (nPosition <= 0 || nPosition >= MAXCOL)
		return 0;
	else
	{
		for (j = nPosition; j < MAXCOL; j++)
		{
			g_szLine[i] = g_szLine[j];
			++i;
		}
		return i;
	}
}