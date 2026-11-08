#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void dispMenu(void)
{
	printf("MENU\n-------------------------------------\n");
	printf("1- List the accounts with zero balances\n2 - Display the account which has the maximum balance\n3 - Exit\n");
}

int readFile(FILE* cust, int* id, double* bal)
{
	int i, j = 0;
	fscanf(cust, "%d", &i);

	id = (int*)malloc(sizeof(int) * i);
	bal = (double*)malloc(sizeof(double) * i);

	while (fscanf(cust, "%d %lf", (id + j), (bal + j)) != EOF && j < i)
		j++;

	return i;
}

void dispZeroBal(double* bal, int* id, int size, double* zeroBal, int* zeroSize)
{
	printf("Accounts with zero balances:\n");
	int i;

	for(i = 0; i < size; i++)
		if (*(bal + i) == 0)
		{
			printf("%d\n", *(id + i));
			*(zeroBal + *zeroSize) = *(id + i);
			zeroSize++;
		}
}

int findMaxBal(double* bal, int size)
{
	int i = 0, max, c = 0;
	max = *(bal + i);

	for(i = 1; i < size; i++)
		if (*(bal + i) > max)
		{
			max = *(bal + i);
			c = i;
		}

	return c;
}

int main(void)
{
	FILE* cust = fopen("customers.txt", "r");
	if (cust == NULL)
		printf("Error!");

	else {
		int req = 0, * id, size, zeroSize = 0, max;
		double* bal, * zeroBal;

		id = (int*)malloc(sizeof(int) * MAX);
		bal = (double*)malloc(sizeof(double) * MAX);
		zeroBal = (double*)malloc(sizeof(double) * MAX);
		size = readFile(cust, id, bal);

		while (req != 3)
		{
			dispMenu();

			do {
				printf("Enter your request: ");
				scanf("%d", &req);
			} while (req < 1 || req > 3);

			switch (req)
			{
			case 1: dispZeroBal(bal, id, size, zeroBal, &zeroSize);
				break;
			case 2: {
				max = findMaxBal(bal, size);
				printf("Account Info which has the maximum balance:\n");
				printf("%d\t %.2f\n", *(id + max), *(bal + max));
			}
				  break;
			default:
				break;
			}
		}
	}
	return 0;
}