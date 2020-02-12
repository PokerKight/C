#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] != s2[j])
				continue;
			else
				break;
		}
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

int main()
{
	char s1[20] = {0};
	char s2[20] = {0};

	scanf("%s", s1);
	scanf("%s", s2);

	squeeze(s1, s2);

	printf("%s\n", s1);

	return 0;
}
