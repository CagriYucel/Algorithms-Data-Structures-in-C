//LG9-Q2b
//reads generates a number between 5 and 15 and draws a right triangle as in example run
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN 5
#define MAX 15

int main(void)
{
	int generatedNum,//random number
		m,
		i, j;//loop counters

	srand(time(NULL));

	generatedNum = rand() % ((MAX + 1) - MIN) + MIN;
	printf("Randomly generated number is: %d\n", generatedNum);

	//right triangle
	for (i = 1; i <= generatedNum; i++)
	{
		for (j = 1; j <= generatedNum - i; j++)
			printf(" ");

		for (m = i; m >= 1; m--)
			printf("*");

		printf("\n");

	}


	return(0);
}