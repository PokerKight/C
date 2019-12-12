#include <stdio.h>

#define MAX_LINE_LEN	1000	/* ������ַ����� */
#define EMPTY_LINE	0	/* ���� */

/*
 * �õ�һ������
 * ����ֵ��������ַ���
 */
int getLine(char szLine[], int nMaxLineLen);

/*
 * ɾ��ÿ��������ĩβ�Ŀո��Ʊ������ɾ����ȫ�ǿո����
 * ����ֵ��ʣ�µ��ַ���
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

int reMove(char szLine[])
{
	int i = 0;

	/* ���ҵ������еĽ�β */
	while (szLine[i] != '\n' && szLine[i] != '\0')
		++i;

	/* ֻ�����������1������'\n' ��2.����'\0' */
	if (szLine[i] == '\n')
		--i;
	else
		--i;
	
	/* ��ȥ1.�ո�2.�Ʊ�� */
	while (i >= 0 && (szLine[i] == ' ' || szLine[i] == '\t')) /* ע��'&&'���ȼ�����'||' */
		--i;
	
	/* ������ǿ��У���׷��'\0' */
	if (i > 0)
	{
		++i;
		szLine[i] = '\0';
	}
	
	return i;
}

