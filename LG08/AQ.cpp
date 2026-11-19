#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <string.h>

int findLastOcc(char* arr, char* str)
{
	int i, alen = strlen(arr), slen = strlen(str), n;

	for (i = alen - slen; i >= 0; i--)
		if (strncmp(arr + i, str, slen) == 0)
			return i;

	return -1;
}

int main(void)
{
	char arr[MAX], str[MAX];
	int a;

	printf("Enter a sentence:");
	scanf("%[^\n]", arr);

	printf("Enter a string:");
	scanf("%s", str);

	a = findLastOcc(arr, str);

	if (a == -1)
		printf("Result: That string cannot be applied, sorry.\n");
	else if (a == 0)
		printf("Result: That's an empty string, sorry.\n");
	else {
		strcpy(arr + a, arr + strlen(arr));
		printf("Result: %s", arr);
	}
	return 0;
}