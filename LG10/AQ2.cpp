#define _CRT_SECURE_NO_WARNINGS
#define MAX 30
#include <stdio.h>
#include <string.h>

int readFromFile(FILE* f, char arr[][MAX])
{
    int i = 0;
    while (fscanf(f, " %[^\n]", (arr + i)) != EOF && i < MAX)
        i++;

    return i;
}

void display(char arr[][MAX], int size)
{
    int i;
    printf("The List of Flowers\n");
    printf("-------------------\n");

    for (i = 0; i < size; i++)
        printf("%s\n", *(arr + i));

    printf("\nThere are 15 flowers in the list\n", size + 1);
}


int binarySearch(char arr[][MAX], int size, char user[], int* comp)
{
    int top = size, bottom = 0, mid;
    *comp = 0;
    while (bottom <= top)
    {
        (*comp)++;
        mid = (top + bottom) / 2;

        if (strcmp(user, *(arr + mid)) == 0)
            return mid;

        else if (strcmp(user, *(arr + mid)) > 0)
            bottom = mid + 1;

        else
            top = mid - 1;
    }
    return -1;
}

int main(void)
{
    FILE* f = fopen("flowers.txt", "r");
    if (f == NULL)
        printf("Error!");

    else {
        int size, a, comp;
        char arr[MAX][MAX], user[MAX] = "";

        size = readFromFile(f, arr);
        display(arr, size);

        do {
            printf("Enter a flower name to search (or end to stop searching):");
            scanf(" %[^\n]", user);

            if (strcmp(user, "end") != 0) {
                a = binarySearch(arr, size, user, &comp);

                if (a == -1)
                    printf("%s could not be found!\n%d comparisons.\n", user, comp);

                else
                    printf("%s found on the index %d in the list\n%d comparisons.\n", user, comp);
            }
        } while (strcmp(user, "end") != 0);
    }
    return 0;
}