#include <stdio.h>

#define MAX_LINE_LEN	1000	/* 行最大字符长度 */

/*
 * 得到一行输入
 * 返回值：输入的字符数
 */
int getLine(char szLine[], int nMaxLineLen);

/*
 * 得到一行输入
 * 反转这个行字符
 */
void reverse(char szLine[]);

int main()
{
	char szLine[MAX_LINE_LEN];

	while (getLine(szLine, MAX_LINE_LEN)) > 0)
	{
		reverse(szLine);
		printf("%s\n", szLine);
	}

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

void reverse(char szLine[])
{
	int i = 0;
	int j = 0;
	char temp = 0;

	/* 下标找到底 */
	while (szLine[i] != '\0')
		++i;
	--i;
	/* 判断结尾是否有换行 */
	if (szLine[i] == '\n')
		--i;

	/* 头尾置换 */
	j = 0;
	while (j < i)
	{
		temp = szLine[j];
		szLine[j] = szLine[i];
		szLine[i] = temp;
		--i;
		++j;
	}

	return;
}