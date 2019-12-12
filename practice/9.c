#include <stdio.h>

#define MAX_LINE_LEN	1000	/* 行最大字符长度 */
#define EMPTY_LINE		0		/* 空行 */
#define LIMIT_LINE_LEN	81

/*
 * 得到一行输入
 * 返回值：输入的字符数
 */
int getLine(char szLine[], int nMaxLineLen);

int main()
{
	int nLineLen;
	char szLine[MAX_LINE_LEN];

	/* 循环得到每行输入的字符长度 */
	while ((nLineLen = getLine(szLine, MAX_LINE_LEN)) > EMPTY_LINE)
		if (nLineLen > LIMIT_LINE_LEN)
			printf("%s", szLine);
		
	return 0;
}

int getLine(char szLine [ ], int nMaxLineLen)
{
	int c = 0;
	int i = 0;

	/* 直到1.输入字符超过最大限制、2.遇到EOF、3.换行才停止 */
	for (i = 0; i < MAX_LINE_LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		szLine[i] = c;
	/* 如果遇到换行，换行符也计入当行的长度 */
	if (c == '\n')
	{
		szLine[i] = c;
		++i;
	}
	/* 结尾加上终止符 */
	szLine[i] = '\0';
	
	return i;
}