#define _CRT_SECURE_NO_WARNINGS
#define LINE 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[LINE], name[LINE];
    int citation;
}pub_t;

void readFromFile(FILE* p, pub_t* pubs, int size)
{
    int i;
    char trash;
    for (i = 0; i < size; i++) {
        fscanf(p, " %[^,],", (pubs + i)->title);
        fscanf(p, "%[^,],", (pubs + i)->name);
        fscanf(p, "%d", &(pubs + i)->citation);
    }
}

void bubbleSort(pub_t* pubs, int size)
{
    int i, sorted = 1;
    pub_t temp;
    do {
        sorted = 1;

        for (i = 0; i < size - 1; i++)
            if ((pubs + i)->citation < (pubs + i + 1)->citation) {
                temp = *(pubs + i);
                *(pubs + i) = *(pubs + i + 1);
                *(pubs + i + 1) = temp;

                sorted = 0;
            }
    } while (sorted != 1);
}

void display(pub_t* pubs, int size)
{
    int i;
    printf("Paper Title\t\t\t\t\t Journal Name\t\t Citation\n");
    printf("------------------------------------------------------------------------------------------\n");

    for (i = 0; i < size; i++)
        printf("%-25s %30s %10d\n", (pubs + i)->title, (pubs + i)->name, (pubs + i)->citation);
}

int main(void)
{
    FILE* p = fopen("publications.txt", "r");
    if (p == NULL)
        printf("Error!");

    else {
        int size, i;
        fscanf(p, "%d", &size);
        pub_t* pubs = (pub_t*)malloc(sizeof(pub_t) * size);

        readFromFile(p, pubs, size);
        bubbleSort(pubs, size);
        display(pubs, size);
    }
    return 0;
}