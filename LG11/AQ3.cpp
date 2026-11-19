#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char user[MAX], name[MAX], sur[MAX], phone[MAX];
} names_t;

int readFromFile(FILE *u, names_t *n)
{
	int i = 0;
	while (fscanf(u, "%s", (n + i)->user) != EOF) {
		fscanf(u, "%s", (n + i)->name);
		fscanf(u, "%s", (n + i)->sur);
		fscanf(u, "%s", (n + i)->phone);
		i++;
	}

	return i;
}

void display(int size, names_t *n)
{
	int i;
	printf("There are %d users in the list\n\n", size);

	printf("    Username          Name         Surname        Phone\n");
	printf("***************  ************  ************* *************\n");

	for (i = 0; i < size; i++)
		printf("%-16s %-13s %-13s %-12s\n", (n + i)->user,
			(n + i)->name, (n + i)->sur, (n + i)->phone);
}

void bubbleSort(int size, names_t* n)
{
	int i, sorted = 0;
	names_t temp;

	do {
		sorted = 1;

		for (i = 0; i < size - 1; i++)
			if (strcmp((n + i)->user, (n + i + 1)->user) > 0)
			{
				temp = *(n + i);
				*(n + i) = *(n + i + 1);
				*(n + i + 1) = temp;
				sorted = 0;
			}
	} while (sorted == 0);
}

int recBinarySearch(names_t *n, char *cho, int top, int bot)
{
	if (top < bot)
		return -1;

	int mid = (top + bot) / 2;

	if (strcmp(cho, (n + mid)->user) > 0)
		return(recBinarySearch(n, cho, top, mid + 1));
	else if (strcmp(cho, (n + mid)->user) < 0)
		recBinarySearch(n, cho, mid - 1, bot);
	else
		return mid;
}

int main(void)
{
	FILE* u = fopen("userinfo.txt", "r");
	if (u == NULL)
		printf("Error!");

	else {
		int size, res;
		char cho[MAX];
		names_t* n = (names_t*)malloc(sizeof(names_t) * MAX);
		
		size = readFromFile(u, n);
		fclose(u);

		bubbleSort(size, n);
		display(size, n);

		printf("Enter the username (END for exit): ");
		scanf("%s", cho);

		while (strcmp(cho, "END") != 0)
		{
			res = recBinarySearch(n, cho, size - 1, 0);
			if (res == -1)
				printf("NOT FOUND\n");
			else
				printf("%-15s %-13s %-10s %-12s\n", (n + res)->user,
					(n + res)->name, (n + res)->sur, (n + res)->phone);

			printf("Enter the username (END for exit): ");
			scanf("%s", cho);
		}
	}
	return 0;
}