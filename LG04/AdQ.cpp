#define _CRT_SECURE_NO_WARNINGS
#define R 10
#define C 7
#include <stdio.h>
#include <stdlib.h>

void readFromFile(FILE *book, int *arr, int n)
{
	int r, c;
	for (r = 0; r < n; r++)
		for (c = 0; c < C; c++)
			fscanf(book, "%d", (*(arr + r) + c));
}

void displayBookingInfo(int *arr, int n)
{
	int r, c;
	for (r = 0; r < n; r++)
		for (c = 0; c < C; c++)
			printf("%d", (*(arr + r) + c));
}

double findAvg(int *arr, int n)
{
	int r, c, sum = 0;
	double avg;

	for (r = 0; r < n; r++)
		for (c = 0; c < C; c++)
			sum += (*(arr + r) + c);
	
	avg = sum / C;

	return avg;
}

int findReceptionistAvg(int *arr, int n, double avg)
{
	int sum = 0, c;

	for (c = 0; c < C; c++)
		sum += (*(arr + n) + c);


	return ;
}

int findMaxSale()
{



}

int main(void)
{
	FILE* book = fopen("bookings.txt", "r");
	if (book == NULL)
		printf("Error!");

	else {
		





	}
	return 0;
}