#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[MAX];
	double price;
	int q;
} pro_t;

int readFromFile(FILE* prod, pro_t* p)
{
	int i = 0, n;
	fscanf(prod, "%d", &n);

	while (i < n)
	{
		fscanf(prod, "%[^0-9] %lf %d", (p + i)->name, 
			&(p + i)->price,
			&(p + i)->q);

		i++;
	}
	return n;
}

void display(pro_t *p, int n)
{
	int i;
	printf("PRODUCT UNIT PRICE QUANTITY\n");

	for (i = 0; i < n; i++) {
		printf("%d. %s %.1f ", i + 1, (p + i)->name,
			(p + i)->price);
		if ((p + i)->q == 0)
			printf("OUT\n");
		else
			printf("%d\n", (p + i)->q);
	}
}

int main(void)
{
	FILE* prod = fopen("products.txt", "r");
	if (prod == NULL)
		printf("Error!");

	else {
		int n, u;
		double money;
		pro_t *p = (pro_t*)malloc(sizeof(pro_t) * MAX);
		n = readFromFile(prod, p);
		
		do {
			display(p, n);
			printf("Enter the product number to purchase (to stop -1): ");
			scanf("%d", &u);

			if (u > 0 && u < n && (p + n)->q > 0) {
				printf("Insert the money:");
				scanf("%lf", &money);

				if (money > (p + u)->q * (p + u)->price) {
					printf("%.2f TL returned back\n", money - (p + u)->q * (p + u)->price);
					(p + u)->q = 0;
				}
				else if (money == (p + u)->q * (p + u)->price)
					(p + u)->q = 0;
				else
					(p + u)->q = (p + u)->q - money * 1.0 / (p + u)->price;
			}
			else if (u > 0 && u < n && (p + n)->q == 0)
				printf("THERE IS NO MORE %s\n", (p + u)->name);

			else if (u > 0 && u < n && (p + u)->price > money)
				printf("Your money is not enough, and returned back\n");

		} while (u != -1);

	}
	return 0;
}