#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>

int main(void)
{
	FILE* res = fopen("result.txt", "w");
	if (res == NULL)
		printf("Error!");

	else {
		int arr[MAX], size = 1, num, i, sum = 0;
		double avg;

		printf("Enter a number: ");
		scanf("%d", &num);

		if (num == -1)
			printf("Program terminated!");

		else {
			num = arr[0];

			while (size < MAX)
			{
				printf("Enter a number: ");
				scanf("%d", &num);

				if (num >= -1)
				{
					arr[size] = num;
					size++;
				}
				if (size == MAX)
					printf("10 number is entered. Array size will be exceeded!!");

				num = arr[0];
				for (i = 0; i < size; i++)
				{
					sum += arr[i];
					if (arr[i] < num && arr[i] != -1)
						num = arr[i];
				}
				if (arr[i - 1] == -1)
				{
					sum++;
					size--;
				}

				avg = 1.0 * sum / size;
				fprintf(res, "Minimum number is %d\nAverage is 6.00\n", num, avg);
				printf("Result is printed!\n");
			}


		}
	}
	return 0;
}