#include <stdio.h>

void expand(char s1[], char s2[])
{
	char temp = 0;
	int i = 0;
	int j = 0;

	while ((temp = s1[i++]) != '\0')
	{
		if (s1[i] == '-' && s1[i+1] >= temp)
		{
			i++;
			while (temp < s1[i])
				s2[j++] = temp++;
		}
		else
			s2[j++] = temp;
	}
	s2[j] = '\0';
}

int main()
{
	char s1[256] = {0};
	char s2[256] = {0};

	scanf("%s", s1);
	expand(s1, s2);
	printf("%s\n", s2);
	
	return 0;
}