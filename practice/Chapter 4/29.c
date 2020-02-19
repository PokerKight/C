#include <stdio.h>
#include <string.h>

void reverser(char s[], int low, int high)
{
	int temp = 0;

	if (low < high)
	{
		temp = s[low];
		s[low] = s[high];
		s[high] = temp;
		reverser(s, ++low, --high);
	}
}

// 无论在何种实现中，我们都应保持相同的用户接口
void reverse(char s[])
{
	reverser(s, 0, strlen(s)-1);
}

int main()
{
	char s[256] = {0};

	scanf("%s", s);
	reverse(s);
	printf("%s\n", s);
	
	return 0;
}
