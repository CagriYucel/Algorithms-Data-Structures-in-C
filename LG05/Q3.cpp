#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int sM;
	int sY;
	int eM;
	int eY;
} det_t;

typedef struct {
	int id;
	int period;
	det_t d;
} war_t;

void readInfo(FILE *war, war_t *w, int n)
{
	int i = 0;

	while (i < n)
	{
		fscanf(war, "%d", &(w + i)->id);
		fscanf(war, "%d", &(w + i)->period);
		fscanf(war, "%d", &(w + i)->d.sM);
		fscanf(war, "%d", &(w + i)->d.sY);
		i++;
	}

	for (i = 0; i < n; i++)
	{
		(w + i)->d.eM = (w + i)->d.sM + (w + i)->period % 12;
		(w + i)->d.eY = (w + i)->d.sY + (w + i)->period / 12;

		if ((w + i)->d.eM > 12)
		{
			(w + i)->d.eY++;
			(w + i)->d.eM %= 12;
		}
	}
}

void display(war_t *w, int n, int m, int y)
{
	int i;
	printf("Warranty Status:\n");
	printf("ID     Period   Start    End     Status\n");
	printf("---------------------------------------\n");

	for (i = 0; i < n; i++)
	{
		int a, b, c;
		printf("%5d", (w + i)->id);
		printf("%5d", (w + i)->period);
		printf("%5d/%4d", (w + i)->d.sM, (w + i)->d.sY);
		printf("%5d/%4d", (w + i)->d.eM, (w + i)->d.eY);

		a = (w + i)->d.eY - (w + i)->d.sY;
		b = (w + i)->d.eM - (w + i)->d.sM;

		if((w + i)->d.eY > y || ((w + i)->d.eY >= y && (w + i)->d.eM >= m))
			printf("\tActive\n");
		else
			printf("\tExpired\n");
	}
}

void findLongestWarranty(war_t *w, int n)
{
	int i, max, a, b = 0;
	max = 0;

	for (i = 1; i < n; i++)
	{
		a = 12 * ((w + i)->d.eY - (w + i)->d.sY) + (w + i)->d.eM - (w + i)->d.sM;
		if (max < a)
		{
			max = a;
			b = i;
		}
	}

	printf("Product with Longest Warranty Remaining: ID %d ", (w + b)->id);
	printf("with %d months left\n", max);
}

int main(void)
{
	FILE* war = fopen("warranty.txt", "r");
	if (war == NULL)
		printf("Error!");

	else {
		int a, y, m = 0;
		fscanf(war, "%d", &a);

		war_t* w = (war_t*)malloc(sizeof(war_t) * a);
		readInfo(war, w, a);

		do {
			printf("Enter current month (1-12): ");
			scanf("%d", &m);
		} while (m < 1 || m > 12);

		printf("Enter current year: ");
		scanf("%d", &y);

		display(w, a, m, y);
		findLongestWarranty(w, a);
	}
	return 0;
}