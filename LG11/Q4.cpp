#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int climb(int n)
{
    if (n == 2)
        return 2;
    if (n == 1)
        return 1;

    return climb(n - 1) + climb(n - 2);
}

int main(void)
{
    int a, n;
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    a = climb(n);
    printf("Total number of ways to climb %d steps: %d\n", n, a);

    return 0;
}