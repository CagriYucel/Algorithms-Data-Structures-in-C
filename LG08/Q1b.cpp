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

void repFirstOcc(char *arr, char *str, char *rep, int occ)
{
	char temp[MAX];
	int slen = strlen(str);

	strncpy(temp, arr, occ);
	temp[occ] = '\0';
	strcat(temp, rep);

	strcat(temp, arr + occ + slen);
	strcpy(arr, temp);
}

int main(void)
{
	char arr[MAX], str[MAX], rep[MAX];
	int a;

	printf("Enter a sentence:");
	scanf("%[^\n]", arr);

	printf("Enter a string:");
	scanf("%s", str);

	a = findFirst(arr, str);
	if (a == -1)
		printf("The sentence does NOT contain the string <%s>\n", str);
	
	else {
		printf("Enter a String to replace:");
		scanf("%s", rep);

		repFirstOcc(arr, str, rep, a);
		printf("New form of the sentence:\n%s", arr);
	}
	return 0;
}