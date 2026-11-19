#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int printDigits(int n)
{
	if (n == 0)
		return n;
	else {
		printf("%d ", n % 10);
		return(printDigits(n / 10));
	}

}

int main(void)
{
	int num;
	
	printf("Enter a number:");
	scanf("%d", &num);

	printf("Digits of the number %d are:\n", num);
	printDigits(num);

	return 0;
}