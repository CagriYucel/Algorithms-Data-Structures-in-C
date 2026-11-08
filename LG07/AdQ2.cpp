#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

typedef struct {
    char deptName[20];
    char deptCode[10];
} codes_t;

int searchCrs(codes_t* c, char dept[][MAX], int n, int dictSize)
{
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(c[i].deptName, dept[n]) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    FILE* crs = fopen("courses.txt", "r");
    if (crs == NULL) {
        printf("Error: File could not be opened!\n");
        return 1;
    }

    char dept[MAX][MAX];
    int code[MAX];
    int i = 0, j, a;

    codes_t c[] = {
        {"CS","11"}, {"THM","61"}, {"CTIS","62"},
        {"ECON","32"}, {"MBA","94"}, {"TURK","95"}
    };
    int dictSize = 6;

    while (i < MAX && fscanf(crs, "%s", dept[i]) != EOF) {
        fscanf(crs, "%d", &code[i]);
        i++;
    }
    fclose(crs);

    for (j = 0; j < i; j++)
    {
        printf("%s %d -> ", dept[j], code[j]);

        a = searchCrs(c, dept, j, dictSize);

        if (a == -1) {
            printf("Error\n");
        }
        else {
            printf("%s%d\n", c[a].deptCode, code[j]);
        }
    }

    return 0;
}