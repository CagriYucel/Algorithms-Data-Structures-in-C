#define _CRT_SECURE_NO_WARNINGS
#define MAX 64
#include <stdio.h>
#include <string.h>

int count(char* str, char* ch, int n)
{
	if (*(str + n) == '\0')
		return 0;

	if (strncmp(str + n, ch, strlen(ch)) == 0)
		return 1 + count(str, ch, n + 1);
	else
		return count(str, ch, n + 1);
}

int main(void)
{
	char str[MAX], ch[MAX];
	int a;

	printf("Enter a string: ");
	scanf("%[^\n]", str);

	printf("Enter a string to search in the sentence: ");
	scanf("%s", ch);

	a = count(str, ch, 0);
	printf("%s\n", str);
	printf("The number of -%s- is %d", ch, a);

	return 0;
}