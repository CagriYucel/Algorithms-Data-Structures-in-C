#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>

int readFromFile(FILE *nums, int *arr)
{
	int i = 0;
	while (fscanf(nums, "%d", (arr + i)) != EOF && i < MAX)
		i++;

	return i;
}

void display(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

int isPerfect(int num)
{
	int sum = 1, j;
	
	for (j = 2; j <= num / 2; j++)
	{
		if (num % j == 0)
			sum += j;
	}
	if (sum == num)
		return 1;

	return 0;
}

int findPerfects(int *arr, int n, int *perf)
{
	int sum = 1, i, j, cnt = 0;

	for (i = 0; i < n; i++)
	{
		j = isPerfect(*(arr + i));
		if (j == 1)
		{
			*(perf + cnt) = *(arr + i);
			cnt++;
		}
	}
	return cnt;
}

void writeToFile(FILE *per, int *perf, int n)
{
	int i;
	for (i = 0; i < n; i++)
		fprintf(per, "%d ", *(perf + i));
}

int main(void)
{
	FILE* per = fopen("perfect.txt", "w"), * nums = fopen("numbersAQ2.txt", "r");
	if (per == NULL || nums == NULL)
		printf("Error!");

	else {
		int arr[MAX], size, perf[MAX];
		printf("The list of numbers in the file:\n");

		size = readFromFile(nums, arr);
		display(arr, size);
		printf("There are %d numbers in the array, ", size );

		size = findPerfects(arr, size, perf);
		printf("%d of them are perfect numbers", size);
		writeToFile(per, perf, size);

		fclose(per);
		fclose(nums);
	}
	return 0;
}