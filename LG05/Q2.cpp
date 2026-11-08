#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int appID;
	int cons;
	double hours;
} app_t;

int readFromFile(FILE *app, app_t *b, int n)
{
	int i = 0;
	while (fscanf(app, "%d", &(b + i)->appID) != EOF && i < n)
	{
		fscanf(app, "%d", &(b + i)->cons);
		fscanf(app, "%lf", &(b + i)->hours);
		i++;
	}

	return i;
}

void display(app_t *b, int n)
{
	int i;
	printf("ID    Cons (W)   Hours    Daily Energy (kWh)\n");
	printf("--------------------------------------------\n");

	for (i = 0; i < n; i++)
	{
		printf("%d", (b + i)->appID);
		printf("%5d", (b + i)->cons);
		printf("%12.2f", (b + i)->hours);
		printf("%14.2f\n", (b + i)->cons * 1.0 / (b + i)->hours);
	}
}

int searchApplience(app_t *b, int n, int id)
{
	int i;
	for (i = 0; i < n; i++)
		if ((b + i)->appID == id)
			return i;
	return -1;
}

int main(void)
{
	FILE* app = fopen("appliances.txt", "r");
	if (app == NULL)
		printf("Error!");

	else {
		int a, num = 1, c;
		fscanf(app, "%d", &a);
		app_t* b = (app_t*)malloc(sizeof(app_t) * a);
		
		a = readFromFile(app, b, a);
		display(b, a);

		do {
			printf("Enter the id of an appliance: ");
			scanf("%d", &num);

			if (num > 0)
			{
				c = searchApplience(b, a, num);
				if (c == -1)
					printf("Appliance not found\n");

				else
					printf("Id : %d\nPower Cons: %d\nHours : %.2f\n");
			}
		} while (num > 0);
	}
	return 0;
}