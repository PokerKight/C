#include <stdio.h>

#define MAX_LINE_LEN	1000	/* 行最大字符长度 */
#define EMPTY_LINE	0	/* 空行 */

/*
 * 得到一行输入
 * 返回值：输入的字符数
 */
int getLine(char szLine[], int nMaxLineLen);

/*
 * 删除每个输入行末尾的空格及制表符，并删除完全是空格的行
 * 返回值：剩下的字符数
 */
int reMove(char szLine[]);


int main()
{
	char szLine[MAX_LINE_LEN];

	while (getLine(szLine, MAX_LINE_LEN) > EMPTY_LINE)
		if (reMove(szLine) > EMPTY_LINE)
			printf("%s\n", szLine);

	return 0;
}

int getLine(char szLine [], int nMaxLineLen)
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

int reMove(char szLine[])
{
	int i = 0;

	/* 先找到输入行的结尾 */
	while (szLine[i] != '\n' && szLine[i] != '\0')
		++i;

	/* 只有两种情况：1，读到'\n' 、2.读到'\0' */
	if (szLine[i] == '\n')
		--i;
	else
		--i;
	
	/* 除去1.空格、2.制表符 */
	while (i >= 0 && (szLine[i] == ' ' || szLine[i] == '\t')) /* 注意'&&'优先级高于'||' */
		--i;
	
	/* 如果不是空行，则追加'\0' */
	if (i > 0)
	{
		++i;
		szLine[i] = '\0';
	}
	
	return i;
}

