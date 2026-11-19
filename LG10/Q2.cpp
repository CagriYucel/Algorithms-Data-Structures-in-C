#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][100], int size)
{
	int i = 0, sorted = 1;
	char temp[100];
	do {
		sorted = 1;
		for(i = 0; i < size - 1; i++)
			if (strcmp(arr[i], arr[i + 1]) < 0)
			{
				strcpy(temp, arr[i]);
				strcpy(arr[i], arr[i + 1]);

				strcpy(arr[i + 1], temp);
				sorted = 0;
			}
	} while (sorted != 1);
}

void display(char arr[][100], int size)
{
	int i;
	printf("Street list\n------------------------------\n");

	for (i = 0; i < size; i++)
		printf("%d) %s\n", i + 1, *(arr + i));
}

int main(void)
{
	char arr[100][100];
	int size = 0;

	do {
		printf("Enter a street name (finish to stop): ");
		scanf(" %[^\n]", arr[size]);

		if(strcmp(arr[size], "finish") != 0)
			size++;

	} while (strcmp(arr[size], "finish"));

	bubbleSort(arr, size);
	display(arr, size);

	return 0;
}