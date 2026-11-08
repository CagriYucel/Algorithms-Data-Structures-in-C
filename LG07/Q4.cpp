#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest(char str[][MAX], int n)
{
	int i, max = strlen(*str), a = 0;

	for(i = 1; i < n; i++)
	{
		if (strlen(*(str + i)) >= max)
		{
			a = i;
			max = strlen(*(str + i));
		}
	}
	return a;
}

int main(void)
{
	char arr[MAX][MAX];
	int max, num = 0;

	printf("Enter a word (or END): ");
	scanf("%s", (arr + num));

	do {
		num++;
		printf("Enter a word (or END): ");
		scanf("%s", (arr + num));
	} while (strcmp(*(arr + num), "END") != 0);

	max = longest(arr, num);
	printf("Longest word: %s\nLength: %d\n", (arr + max), strlen(*(arr + max)));

	return 0;
}