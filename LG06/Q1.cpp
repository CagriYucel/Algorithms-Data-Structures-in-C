#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[MAX];
	double freq;
	int hits;
} rad_t;

void read(rad_t *a, FILE *radio)
{
	int i = 0;
	while (fscanf(radio, "%lf", &(a + i)->freq) != EOF && i < MAX)
	{
		fscanf(radio, "%s", (a + i)->name);
		fscanf(radio, "%d", &(a + i)->hits);
		i++;
	}
}

void display(int num, rad_t *a)
{
	int i;
	printf("Frequency Name         #ofHits\n");
	printf("********* ************ *******\n");

	for (i = 0; i < num; i++)
	{
		printf("%9.1f %-12s %7d\n", (a + i)->freq,
			(a + i)->name,
			(a + i)->hits);
	}
}

int findMaxHits(rad_t *a, int num)
{
	int max = 0, i;
	for (i = 1; i < num; i++)
		if ((a + max)->hits < (a + i)->hits)
			max = i;
	
	return max;
}

int findRadio(rad_t *a, int num, double fre)
{
	int i;
	for (i = 0; i < num; i++)
		if (fre == (a + i)->freq)
			return i;
	
	return -1;
}

int main(void)
{
	FILE* radio = fopen("radio.txt", "r");
	if (radio == NULL)
		printf("Error!");

	else {
		int n, b;
		double fre = 0;
		do {
			printf("How many radio information will you read: ");
			scanf("%d", &n);
			if (n < 1 || n > 20)
				printf("Error!!! Please enter a number 1-20\n");
		} while (n < 1 || n > 20);

		rad_t* a = (rad_t*)malloc(sizeof(rad_t) * n);
		read(a, radio);
		display(n, a);

		b = findMaxHits(a, n);
		printf("The radio %s has the maximum hits\nFrequency: %.1f\nHits : %d\n", (a + b)->name,
			(a + b)->freq,
			(a + b)->hits);

		printf("Enter a radio frequency to search: ");
		scanf("%lf", &fre);
		b = findRadio(a, n, fre);

		if (b == -1)
			printf("Sorry! There is no radio on the given frequency :(\n");
		else
			printf("Radio <%s> is on the %.1f frequency\n", (a + b)->name, (a + b)->freq);

		free(a);
	}
	return 0;
}