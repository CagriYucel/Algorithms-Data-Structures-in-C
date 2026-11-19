#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printNumbers(int a)
{
    int b;

    if (a != 0) {
        b = a;
        printNumbers(--a);
        printf("%d ", b);
    }
}

void printLines(int n)
{
    if (n != 0) {
        printLines(n - 1);
        printNumbers(n);
        printf("\n");
    }
}

int main(void)
{
    int n;
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    printLines(n);

    return 0;
}
