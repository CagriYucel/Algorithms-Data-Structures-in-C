#define _CRT_SECURE_NO_WARNINGS
#define MAX 15
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* v = fopen("visitors.txt", "r");
	if (v == NULL)
		printf("Error!");

	else {
		int arr[MAX], i = 0, sorted = 1, temp, size;
		while (fscanf(v, "%d", (arr + i)) != EOF && i < MAX)
			i++;
		
		size = i;
		do {
			sorted = 1;
			i = 0;
			for(i = 0; i < size - 1; i++)
				if (*(arr + i) > *(arr + i + 1)) {
					temp = *(arr + i);
					*(arr + i) = *(arr + i + 1);
					*(arr + i + 1) = temp;
					sorted = 0;
				}
		} while (sorted != 1);

		printf("#of visitors\n**************\n");
		for (i = 0; i < size; i++)
			printf("%7d\n", *(arr + i));
	}
	return 0;
}