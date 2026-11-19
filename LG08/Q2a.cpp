#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <string.h>

int findFirst(char* arr, char* str)
{
	int i, slen = strlen(str), arrlen = strlen(arr);
	for (i = 0; i <= arrlen - slen; i++)
		if (strncmp(str, arr + i, slen) == 0)
			return i;

	return -1;
}

void delFirst(char* arr, char* str, int n)
{
	int i, alen = strlen(arr), slen = strlen(str);
	strcpy(arr + n, arr + n + slen + 1);
}

int main(void)
{
	char arr[MAX], str[MAX];
	int a;

	printf("Enter a sentence:");
	scanf("%[^\n]", arr);

	printf("Enter a String to search:");
	scanf("%s", str);

	a = findFirst(arr, str);
	if (a == -1)
		printf("The sentence does NOT contain the string <%s>", str);
	else {
		delFirst(arr, str, a);
		printf("The new form of the sentence after deletion:\n%s", arr);
	}
	return 0;
}