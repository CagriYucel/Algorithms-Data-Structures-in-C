#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define WEEK 7
#define CITY 15

void readFromFile(FILE* w, int** arr, int n)
{
	int r, c;
	for (r = 0; r < n; r++)
		for (c = 0; c < n; c++)
			fscanf(w, "%d", &(*(*(arr + r) + c)));
}

void display(int** arr, int n)
{
	int r, c;
	printf("City   M   T   W   R   F   S   S\n----   ---   ---   ---   ---   ---   ---   ---\n");

	for (r = 0; r < n; r++)
	{
		printf("%3d", r + 1);
		for (c = 0; c < WEEK; c++)
			printf("%4d", *(*(arr + r) + c));
		printf("\n");
	}
}

void findColdestDay(int** arr, int n, int* city, int* day)
{
	int r = 0, c = 0, cold = *(*(arr + r) + c);
	*city = *day = 1;

	for(r = 0; r < n; r++)
		for(c = 1; c < WEEK; c++)
			if (cold > *(*(arr + r) + c))
			{
				cold = *(*(arr + r) + c);
				*city = r;
				*day = c;
			}
}

int main(void)
{
	FILE* weat = fopen("weather.txt", "r");
	if (weat == NULL)
		printf("Error!");

	else {
		int num, a, city, day;
		do {
			printf("How many city will be displayed in the report?");
			scanf("%d", &num);
		} while (num < 1 || num > CITY);

		int** arr = (int**)malloc(sizeof(int) * num);
		for (a = 0; a < num; a++)
			*(arr + a) = (int*)malloc(sizeof(int) * WEEK);

		readFromFile(weat, arr, num);
		display(arr, num);
		findColdestDay(arr, num, &city, &day);

		switch (day % 7)
		{
		case 0: printf("City %d is the coldest one with the temperature %d on MONDAY", city + 1, *(*(arr + city) + day));
			break;
		case 1: printf("City %d is the coldest one with the temperature %d on TUESDAY", city + 1, *(*(arr + city) + day));
			break;
		case 2: printf("City %d is the coldest one with the temperature %d on WEDNESDAY", city + 1, *(*(arr + city) + day));
			break;
		case 3: printf("City %d is the coldest one with the temperature %d on THURSDAY", city + 1, *(*(arr + city) + day));
			break;
		case 4: printf("City %d is the coldest one with the temperature %d on FRIDAY", city + 1, *(*(arr + city) + day));
			break;
		case 5: printf("City %d is the coldest one with the temperature %d on SATURDAY", city + 1, *(*(arr + city) + day));
			break;
		default: printf("City %d is the coldest one with the temperature %d on SUNDAY", city + 1, *(*(arr + city) + day));
			break;
		}
		free(arr);
	}
	return 0;
}