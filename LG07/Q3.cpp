#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#define LINE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* t = fopen("tennis.txt", "r");
	if (t == NULL)
		printf("Error!");

	else {
		char arr[MAX];
		int i = 0, a = 0;

		while (fscanf(t, "%s", arr) != EOF && i < LINE)
		{
			if (strcmp("EOL", arr) == 0)
			{
				i++;
				printf("%d. line contains %d words\n", i, a);
				a = 0;
			}
			a++;
		}
	}
	return 0;
}