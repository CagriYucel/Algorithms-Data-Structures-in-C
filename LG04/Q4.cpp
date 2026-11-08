#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char code[MAX];
	double price;
	int discount;
} flights_t;

int main(void)
{
	FILE* ticket = fopen("tickets.txt", "r");
	if (ticket == NULL)
		printf("Error!");

	else {
		int a, i = 0;
		fscanf(ticket, "%d", &a);
		printf("There are %d tickets in the market\n", a);


		flights_t* flights = (flights_t*)malloc(sizeof(flights_t) * a);
		printf("FLIGHT CODE   PRICE   DISCOUNT DISC. PRICE  SAVED AMOUNT\n");
		printf("************ ********* ******** *********** ************\n");

		while (fscanf(ticket, "%s", (flights + i)->code) != EOF && i < a)
		{
			fscanf(ticket, "%lf", &(flights + i)->price);
			fscanf(ticket, "%d", &(flights + i)->discount);
			i++;
		}

		for (i = 0; i < a; i++)
		{
			printf("%s %15.2f %6d\t", (flights + i)->code, (flights + i)->price, (flights + i)->discount);
			printf("%8.2f\t", (flights + i)->price * (flights + i)->discount / 100 * 1.0);
			printf("%6.2f\n", (flights + i)->price - ((flights + i)->price * (flights + i)->discount / 100 * 1.0));
		}
	}
	return 0;
}