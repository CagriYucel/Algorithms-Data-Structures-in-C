#define _CRT_SECURE_NO_WARNINGS
#define MAX 64
#include <stdio.h>
#include <string.h>

int count(char* str, char* ch, int n)
{
	if (*(str + n) == '\0')
		return 0;

	if (*(str + n) == *ch || *(str + n) == *ch - 'A' - 'a' || *(str + n) == *ch + 'A' - 'a')
		return 1 + count(str, ch, n + 1);
	else
		return count(str, ch, n + 1);
}

int main(void)
{
	char str[MAX], ch;
	int a;

	printf("Enter a string: ");
	scanf("%[^\n]", str);

	printf("Enter a character: ");
	scanf(" %c", &ch);

	a = count(str, &ch, 0);
	printf("%s\n", str);
	printf("The number of '%c' is %d", ch, a);

	return 0;
}