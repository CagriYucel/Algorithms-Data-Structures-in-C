#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>

int main(void)
{
	char arr[MAX];
	printf("Enter a sentence: ");
	scanf("%s", arr);
	printf("The sentence is: %s\n", arr);

	printf("Enter a sentence : \n");
	scanf("%[^\n]", arr);
	printf("The sentence is: %s\n", arr);

	printf("Enter a sentence : ");
	scanf("%[^0-9]", arr);
	printf("The sentence is: %s\n", arr);

	return 0;
}