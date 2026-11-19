#define MAX 15
#include <stdio.h>

int readList(FILE *nums, int arr[])
{
	int i = 0;
	while (fscanf(nums, "%d", &arr[i]) != EOF)
		i++;

	return i;
}

int findSum(int arr[], int size)
{
	int sum = 0, i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 3 == 0)
			sum += arr[i];
	}

	return sum;
}

int main(void)
{
	FILE* nums = fopen("numbers.txt", "r");
	if (nums == NULL)
		printf("Error!");

	else {
		int sum, size, arr[MAX];
		size = readList(nums, arr);

		sum = findSum(arr, size);
		printf("Sum excluding the numbers that are divisible by 3: %d", sum);

		fclose(nums);
	}
	return 0;
}