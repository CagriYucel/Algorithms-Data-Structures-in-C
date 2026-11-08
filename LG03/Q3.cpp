#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double calcCons(int arr[], int size)
{
	int i, sum = 0;
	double cons;
	
	for (i = 0; i < size; i++)
		sum += *(arr + i);

	cons = size * 1000.0 / sum;

	return cons;
}

void inputDist(int* arr, int num)
{
	int i = 0;
	printf("Enter distances traveled after each refuel (km): ");

	while (i < num)
	{
		scanf("%d", (arr + i));
		i++;
	}

}

int main(void)
{
	int* arr, refuel = 1;
	double con;

	while (refuel < 0)
	{
		printf("How many times did you refuel?");
		scanf("%d", &refuel);

		if (refuel < 0)
		{
			arr = (int*)malloc(sizeof(int) * refuel);

			inputDist(arr, refuel);
			con = calcCons(arr, refuel);

			printf("The average fuel consumption per 50 km: %d\n", con);
			free(arr);
		}
	}
	return 0;
}