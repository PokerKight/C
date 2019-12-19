#include <stdio.h>

#define MAX_LINE_LEN	1000	/* ������ַ����� */

/*
 * �õ�һ������
 * ����ֵ��������ַ���
 */
int getLine(char szLine[], int nMaxLineLen);

/*
 * �õ�һ������
 * ��ת������ַ�
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

void reverse(char szLine[])
{
	int i = 0;
	int j = 0;
	char temp = 0;

	/* �±��ҵ��� */
	while (szLine[i] != '\0')
		++i;
	--i;
	/* �жϽ�β�Ƿ��л��� */
	if (szLine[i] == '\n')
		--i;

	/* ͷβ�û� */
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