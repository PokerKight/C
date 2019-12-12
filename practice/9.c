#include <stdio.h>

#define MAX_LINE_LEN	1000	/* ������ַ����� */
#define EMPTY_LINE		0		/* ���� */
#define LIMIT_LINE_LEN	81

/*
 * �õ�һ������
 * ����ֵ��������ַ���
 */
int getLine(char szLine[], int nMaxLineLen);

int main()
{
	int nLineLen;
	char szLine[MAX_LINE_LEN];

	/* ѭ���õ�ÿ��������ַ����� */
	while ((nLineLen = getLine(szLine, MAX_LINE_LEN)) > EMPTY_LINE)
		if (nLineLen > LIMIT_LINE_LEN)
			printf("%s", szLine);
		
	return 0;
}

int getLine(char szLine [ ], int nMaxLineLen)
{
	int c = 0;
	int i = 0;

	/* ֱ��1.�����ַ�����������ơ�2.����EOF��3.���в�ֹͣ */
	for (i = 0; i < MAX_LINE_LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		szLine[i] = c;
	/* ����������У����з�Ҳ���뵱�еĳ��� */
	if (c == '\n')
	{
		szLine[i] = c;
		++i;
	}
	/* ��β������ֹ�� */
	szLine[i] = '\0';
	
	return i;
}