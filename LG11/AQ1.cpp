#define _CRT_SECURE_NO_WARNINGS
#define MAX 64
#include <stdio.h>
#include <string.h>

void rev(char *st, int top, int bot)
{
	if (bot <= top) {
		char temp = *(st + bot);
		*(st + bot) = *(st + top);
		*(st + top) = temp;

		rev(st, top - 1, bot + 1);
	}
}

int main(void)
{
	char st[MAX];

	printf("Enter a string: ");
	scanf("%[^\n]", st);

	rev(st, strlen(st) - 1, 0);
	printf("Reversed string: %s\n", st);
	
	return 0;
}