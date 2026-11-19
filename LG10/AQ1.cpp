#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[MAX], surname[MAX];
    int year;
} peop_t;

int readFromFile(FILE* p, peop_t* pe)
{
    int i = 0;
    char trash;
    while (fscanf(p, "%s", (pe + i)->name) != EOF && i < MAX) {
        fscanf(p, "%s", (pe + i)->surname);
        fscanf(p, "%d", &(pe + i)->year);
        i++;
    }
    return i;
}

void bubbleSortTwoLevel(peop_t* pe, int size)
{
    int i, sorted = 1;
    peop_t temp;
    do {
        sorted = 1;

        for (i = 0; i < size - 1; i++)
            if (strcmp((pe + i)->surname, (pe + i + 1)->surname) > 0) {
                temp = *(pe + i);
                *(pe + i) = *(pe + i + 1);
                *(pe + i + 1) = temp;

                sorted = 0;
            }
    } while (sorted != 1);

    do {
        sorted = 1;

        for (i = 0; i < size - 1; i++)
            if (strcmp((pe + i)->name, (pe + i + 1)->name) > 0 && strcmp((pe + i)->surname, (pe + i + 1)->surname) == 0)
            {
                temp = *(pe + i);
                *(pe + i) = *(pe + i + 1);
                *(pe + i + 1) = temp;

                sorted = 0;
            }
    } while (sorted != 1);
}

int main(void)
{
    FILE* p = fopen("people.txt", "r");
    if (p == NULL)
        printf("Error 1!");

    else {
        peop_t* pe = (peop_t*)malloc(sizeof(peop_t) * MAX);
        int size, i;

        size = readFromFile(p, pe);
        bubbleSortTwoLevel(pe, size);

        FILE* sort = fopen("sorted.txt", "w");
        if (sort == NULL)
            printf("Error 2!");
        else {
            for (i = 0; i < size; i++)
                fprintf(sort, "%s %s %d\n", (pe + i)->name, (pe + i)->surname, (pe + i)->year);
        }
    }
    return 0;
}