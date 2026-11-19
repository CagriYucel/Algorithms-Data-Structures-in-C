#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	//declare variables
	int p, i, terms, fact = 1;
	double z = 0, term, partialSum = 0;

	//getting input
	do {
		printf("Enter the value of p:");
		scanf("%d", &p);
		if (p == 1)
			printf("Division by zero\n");
	} while (p == 1);

	printf("Enter the value of terms:");
	scanf("%d", &terms);

	//calculation and output
	for (i = 1; i <= terms; i++)
	{
		fact = fact * i;
		term = pow(-1, i + 1) * (fact + i + 1) / pow(p - 1, 2 * i);
		partialSum = partialSum + term;
		z = z + term;
		printf("Term %d = %f\n", i, term);
		printf("Partial sum = %f\n", partialSum);
	}

	printf("z = %f", z);

	return(0);
}