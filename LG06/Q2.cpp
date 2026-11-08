#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	char type;
	int num;
} room_t;

typedef struct {
	char name[MAX];
	int birth;
	int day;
	double pay;
	room_t r;
} cus_t;

void readFromFile(FILE* cust, cus_t* c, int n)
{
	int i = 0;
	double price;
	while (fscanf(cust, "%s", (c + i)->name) != EOF && i < n)
	{
		fscanf(cust, "%d %d %d %c", &(c + i)->birth, 
			&(c + i)->day,
			&(c + i)->r.num,
			&(c + i)->r.type);
		if ((c + i)->r.type == 'S')
			price = 3000.0;
		else if ((c + i)->r.type == 'T')
			price = 7500.0;
		else
			price = 10500.0;

		(c + i)->pay = price * (c + i)->day;
		i++;
	}
}

void displayAll(cus_t* c, int n)
{
	int i;
	printf("Name\t\t BYear   Day   Room Num   Type\t Payment\n");
	printf("-------------------------------------------------------\n");
	
	for (i = 0; i < n; i++)
	{
		printf("%s\t %d\t %d\t %d %c\t %.2f\n", (c + i)->name,
			(c + i)->birth,
			(c + i)->day,
			(c + i)->r.num,
			(c + i)->r.type,
			(c + i)->pay);
	}
}

double calcTotalEarnings(cus_t* c, int n)
{
	int i;
	double sum = 0;
	for (i = 0; i < n; i++)
		sum += (c + i)->pay;

	return sum;
}

int findCustMaxPay(cus_t* c, int n)
{
	int i, a = 0;

	for (i = 1; i < n; i++)
		if ((c + a)->pay < (c + i)->pay)
			a = i;

	return a;
}

int main(void)
{
	FILE* cust = fopen("customers.txt", "r");
	if (cust == NULL)
		printf("Error!");

	else {
		int n, b;
		double a;
		srand(time(NULL));
		n = rand() % 16 + 5;

		cus_t* c = (cus_t*)malloc(sizeof(cus_t) * n);
		readFromFile(cust, c, n);

		printf("%d Customers' info will be read:", n);
		displayAll(c, n);

		a = calcTotalEarnings(c, n);
		printf("Total Earnings of the hotel : %.2f\n", a);

		b = findCustMaxPay(c, n);
		printf("The Customer having maximum payment for accommodation:\n");
		printf("%s with the price %.2f TL", (c + b)->name, (c + b)->pay);
	}
	return 0;
}