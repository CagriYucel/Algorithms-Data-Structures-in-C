#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>
#include <math.h>

int readFromTxt(FILE *nums, int arr[])
{
	int i = 0;
	while (fscanf(nums, "%d", &arr[i]) != EOF)
		i++;

	return i;
}

void findTwoAvg(int arr[], int size, double* Aavg, double* Havg)
{
	int i;
	double sum = 0;
	*Aavg = *Havg = 0;

	for (i = 0; i < size; i++)
		sum += arr[i];

	*Aavg = 1.0 * sum / size;
	sum = 0;

	for (i = 0; i < size; i++)
		sum += 1.0 / arr[i];

	*Havg = 1.0 * size / sum;
}

int main(void)
{
	FILE* nums = fopen("numbers.txt", "r");
	if (nums == NULL)
		printf("Error!");

	else {
		int size, arr[MAX] = { 0 };
		double Aavg = 0, Havg = 0;

		size = readFromTxt(nums, arr);
		findTwoAvg(arr, size, &Aavg, &Havg);

		printf("Arithmetic Average is %.2f\n", Aavg);
		printf("Harmonic Average is %.2f\n", Havg);
	}
	return 0;
}