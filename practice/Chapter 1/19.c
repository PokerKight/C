#include <stdio.h>

int any(char s1[], char s2[])
{
	int i = 0;
	int j = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i+j] == s2[j])
				continue;
			else
				break;
		}
		if (s2[j] == '\0')
			return i;
	}
	
	return -1;
}

int main()
{
	char s1[20] = {0};
	char s2[20] = {0};
	int position = 0;

	scanf("%s", s1);
	scanf("%s", s2);

	position = any(s1, s2);
	printf("%d\n", position);

	return 0;
}
