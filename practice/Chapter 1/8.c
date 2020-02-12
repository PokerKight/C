#include <stdio.h>

/* 
 *HIST means Histogram
 */

#define MAX_HIST_LEN	15
#define MAX_WORD_LEN 	15
#define IN		1
#define OUT		0

int main()
{
	int c = 0;
	int nState = OUT;
	int nWordLen = 0;
	int aWordLenList[MAX_WORD_LEN] = {0};
	int i = 0;
	int nMaxValue = 0;
	int nOverflow = 0;
	int nHistLen = 0;
	
	/* set word's length to aWordLenList */
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			nState = OUT;
			if (nWordLen > 0)
				if (nWordLen < MAX_WORD_LEN)
					++aWordLenList[nWordLen];
				else
					++nOverflow;
			nWordLen = 0;
		}
		else if (nState == OUT)
		{
			nState = IN;
			nWordLen = 1;
		}
		else
			++nWordLen;
	}

	/* get nMaxValue in aWordLenList */
	for (i = 1; i < MAX_WORD_LEN; ++i)
	{
		if (aWordLenList[i] > nMaxValue)
			nMaxValue = aWordLenList[i];
	}

	/* print nHistLen */
	for (i = 1; i < MAX_WORD_LEN; ++i)
	{
		printf("%5d - %5d : ", i, aWordLenList[i]);
		if (aWordLenList[i] > 0)
		{
			/*calc nHistLen*/
			if ((nHistLen = aWordLenList[i] * MAX_HIST_LEN / nMaxValue) <= 0)
				nHistLen = 1;
		}
		else
			nHistLen = 0;
		while (nHistLen > 0)
		{
			putchar('*');
			--nHistLen;
		}
		putchar('\n');
	}
	if (nOverflow > 0)
		printf("There are %d words >= %d \n", nOverflow, MAX_WORD_LEN);

	return 0;
}	
