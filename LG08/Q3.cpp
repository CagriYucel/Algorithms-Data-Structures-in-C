#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <string.h>

int findAllOcc(char* arr, char* str, int* occ)
{
	int i, size = 0, slen = strlen(str), alen = strlen(arr);
	for (i = 0; i <= alen - slen; i++)
		if (strncmp(arr + i, str, slen) == 0)
			occ[size++] = i;

	return size;
}

int main(void)
{
	char arr[MAX], str[MAX];
	int i, occ[MAX], size;

	printf("Enter a sentence:");
	scanf("%[^\n]", arr);

	printf("Enter a string:");
	scanf("%s", str);

	size = findAllOcc(arr, str, occ);
	if (size == 0)
		printf("The sentence does NOT contain the string <%s>", str);
	else {
		printf("All occurences of the str <%s>: ");
		for (i = 0; i < size; i++)
			printf("%3d", occ[i]);
	}
	return 0;
}