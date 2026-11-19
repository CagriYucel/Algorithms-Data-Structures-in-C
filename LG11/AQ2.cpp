#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isAckermann(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (m > 0 && n == 0)
		return isAckermann(m - 1, 1);
	else if (m > 0 && n > 0)
		return isAckermann(m - 1, isAckermann(m, n - 1));
}

int main(void)
{
	int l, m, n;
	
	printf("Enter the value of m: ");
	scanf("%d", &m);

	printf("Enter the value of n: ");
	scanf("%d", &n);

	if (m <= 0 || m >= 4 || n <= 0)
		printf("The value of both m & n had to be positive values and m must be less than 4. Exiting.\n");
	else {
		l = isAckermann(m, n);
		printf("The result is %d\n", l);
	}
	
	return 0;
}