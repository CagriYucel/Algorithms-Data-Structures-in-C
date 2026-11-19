#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int num, menu, i, j, k, m;

	do {
		do {
			printf("	MENU	\n");
			printf("-------------\n");
			printf("1. Right Triangle\n");
			printf("2. Isosceles Triangle\n");
			printf("3. Exit\n");

			printf("Enter your choice: ");
			scanf("%d", &menu);

		} while (menu < 1 || menu > 4);

		if (menu != 3)
		{
			srand(time(NULL));
			num = rand() % 8 + 2;
			printf("Random number is %d\n", num);
		}

		switch (menu)
		{
		case 1:
			for (i = 1; i <= num; i++)
			{
				for (j = 1; j <= num - i; j++)
					printf(" ");

				for (m = i; m >= 1; m--)
					printf("%d", m);

				printf("\n");
			}
			break;
		case 2:
			for (i = 1; i <= num; i++)
			{
				for (j = 1; j <= num - i; j++)
					printf(" ");

				for (m = i; m >= 1; m--)
					printf("%d", m);

				for (k = 2; k <= i; k++)
					printf("%d", k);

				printf("\n");
			}
			break;
		}
	} while (menu != 3);

	return(0);
}