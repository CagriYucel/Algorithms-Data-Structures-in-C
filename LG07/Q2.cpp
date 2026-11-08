#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrLen(char* str)
{
	int i;
	i = strlen(str);

	return i;
}

int main(void)
{
	FILE* w = fopen("words.txt", "r");
	if (w == NULL)
		printf("Error!");

	else {
		FILE* res = fopen("result.txt", "w");
		char arr[MAX];
		int i = 0, a;

		while (fscanf(w, "%s", arr) != EOF)
		{
			a = myStrLen(arr);
			fprintf(res, "%s-%d\n", arr, a);
		}
	}
	return 0;
}