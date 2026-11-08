#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int propID;
	char propType;
	double price;
	int bed;
	int bath;
} prop_t;

void readFromFile(FILE *f, int size, prop_t *arr)
{
	int i = 0;
	while (i < size)
	{
		fscanf(f, "%d", &arr[i].propID);
		fscanf(f, " %c", &arr[i].propType);
		fscanf(f, "%lf", &arr[i].price);
		fscanf(f, "%d", &arr[i].bed);
		fscanf(f, "%d", &arr[i].bath);
		i++;
	}
}

void displayAndCalculate(prop_t *arr, int size)
{
	int i;
	printf("Real Estate Agency\n");
	printf("ID\t Type\t Price (TL)\t Bedroom#   Bathroom#\n");
	printf("******************************************************\n");

	for (i = 0; i < size; i++)
	{
		printf("%d \t", arr[i].propID);
		if (arr[i].propType == 'S')
			printf("Sold\t");
		else
			printf("Rented\t");
		printf("  %.2f\t\  ", arr[i].price);
		printf("%3d\t %8d\n", arr[i].bed, arr[i].bath);
	}
}

int main(void)
{
	FILE* prop = fopen("properties.txt", "r");

	if (prop == NULL)
		printf("Error!");

	else {
		int n;
		fscanf(prop, "%d", &n);

		prop_t p;
		prop_t* arr, * a;
		
		a = &p;
		arr = (prop_t*)malloc(sizeof(prop_t) * n);

		readFromFile(prop, n, arr);
		displayAndCalculate(arr, n);
	}
	return 0;
}