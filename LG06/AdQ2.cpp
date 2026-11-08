#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(void)
{
	int n = 0;
	printf("MENU\n1.Fill array with Random numbers\n2.Display Array Elements\n");
	printf("3.Display #of Occurrences of a value\n4.Exit\n");
	
	do {
		printf("Enter your choice : ");
		scanf("%d", &n);
	} while (n < 1 || n > 4);

	return n;
}

void fillArray(int **arr, int dim)
{
	int r, c, num;
	srand(time(NULL));

	for(r = 0; r < dim; r++)
		for (c = 0; c < dim; c++)
		{
			num = rand() % 180 + 20;
			*(*(arr + r) + c) = num;
		}
}

void displayArray(int **arr, int dim)
{
	int r, c;
	printf("Content of the array\n********************\n");

	for (r = 0; r < dim; r++) {
		for (c = 0; c < dim; c++)
			printf("%d ", *(*(arr + r) + c));
		printf("\n");
	}
}

int searchValue(int** arr, int dim, int n)
{
	int r, c, cnt = 0;

	for (r = 0; r < dim; r++)
		for (c = 0; c < dim; c++)
			if (*(*(arr + r) + c) == n)
				cnt++;

	return cnt;
}

int main(void)
{
	int dim = 0, cho = 0, num, a;
	do {
		printf("Please Enter the dimension: ");
		scanf("%d", &dim);
	} while (dim <= 0);

	int** arr = (int**)malloc(sizeof(int) * dim);
	for (a = 0; a < dim; a++)
		*(arr + a) = (int*)malloc(sizeof(int) * dim);

	while (cho != 4)
	{
		cho = menu();
		switch (cho)
		{
		case 1: {
			fillArray(arr, dim);
			printf("Array filled with random numbers (20-199)\n");
		}
			break;
		case 2: displayArray(arr, dim);
			break;
		case 3: {
			printf("Enter the value to search:");
			scanf("%d", &num);
			a = searchValue(arr, dim, num);

			if (a == 0)
				printf("The array does NOT contain the value %d\n", num);
			else
				printf("The number of occurences: %d\n", a);
		}
			break;
		default:
			break;
		}
	}
	return 0;
}