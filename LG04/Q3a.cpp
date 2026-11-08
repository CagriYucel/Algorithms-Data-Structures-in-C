#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20

int main(void)
{
	char word[MAX];
	printf("Enter a word: ");
	scanf("%s", word);

	printf("You have entered the word: %s\n", word);

	return 0;
}