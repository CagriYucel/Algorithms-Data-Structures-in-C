#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20

int main(void)
{
	char word[MAX];
	FILE* words = fopen("words_q3.txt", "r");
	if (words == NULL)
		printf("Error!");

	else {
		printf("The words in the file\n*********************\n");
		while (fscanf(words, "%s", word) != EOF)
		{
			printf("%s\n", word);
		}
	}
	fclose(words);

	return 0;
}