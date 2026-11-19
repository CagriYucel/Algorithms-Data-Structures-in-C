#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read(FILE* s, int* arr)
{
    int i = 0;

    while (fscanf(s, "%d", (arr + i)) != EOF && i < MAX)
        i++;

    return i;
}

int binarySearch(int* arr, int size, int num, int* comp)
{
    int top = size, bottom = 0, mid;
    *comp = 0;
    while (bottom <= top)
    {
        (*comp)++;
        mid = (top + bottom) / 2;
        if (num == *(arr + mid))
            return mid + 1;
        else if (num > *(arr + mid))
            bottom = mid + 1;
        else
            top = mid - 1;

    }
    return -1;
}

int main(void)
{
    FILE* s = fopen("steps.txt", "r");
    if (s == NULL)
        printf("Error!");

    else {
        int arr[MAX], size, num, res, comp;
        size = read(s, arr);

        printf("Enter value to find : ");
        scanf("%d", &num);

        res = binarySearch(arr, size, num, &comp);

        if (res == -1)
            printf("The number is NOT found in the steps.txt\n%d comparisons.", comp);
        else
            printf("%d is found at %d. line\n%d comparisons.", num, res, comp);
    }
    return 0;
}