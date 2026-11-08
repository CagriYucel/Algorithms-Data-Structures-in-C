#define _CRT_SECURE_NO_WARNINGS
#define MAX 15
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int readFromTxt(FILE *num, int *arr)
{
	int i = 0;
	while (fscanf(num, "%d", &(*(arr + i))) != EOF)
		i++;

	return i;
}

void findAvgStdDev(int *arr, int size, double *avg, double *dev)
{
	int i, sum = 0;

	for (i = 0; i < size; i++)
		sum += *(arr + i);

	*avg = sum * 1.0 / size;
	
	double variance = 0;

	for (i = 0; i < size; i++)
		variance += pow(*(arr + i) - *avg, 2);

	*dev = sqrt(variance / size);
}

int main(void)
{
	FILE* num = fopen("numbersDMA.txt", "r");
	if (num == NULL)
		printf("Error!");

	else {
		int size;
		double avg, dev;
		avg = 0;
		dev = 0;

		int *arr = (int*)malloc(sizeof(int) * MAX);
		size = readFromTxt(num, arr);
		findAvgStdDev(arr, size, &avg, &dev);

		printf("The average of elements is: %.2f\n", avg);
		printf("The standard deviation of elements is: %.2f\n", dev);
	}
	return 0;
}