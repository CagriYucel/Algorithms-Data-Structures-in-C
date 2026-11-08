#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readFile(FILE* word, char** arr, int r, int c)
{
    int row, col;

    for (row = 0; row < r; row++) {
        for (col = 0; col < c; col++) {
            fscanf(word, " %c", &arr[row][col]);
        }
    }
}

void displayWords(char** arr, int r, int c)
{
    int row, col;
    printf("WORDS\n******\n");

    for (row = 0; row < r; row++) {
        for (col = 0; col < c; col++) {
            printf("%c", arr[row][col]);
        }
        printf("\n");
    }
}

void displayWordsSpecCol(char** arr, int r, int c)
{
    int row, col = 0;

    do {
        printf("Enter the column number (1-%d): ", c);
        scanf("%d", &col);
    } while (col < 1 || col > c);

    for (row = 0; row < r; row++) {
        printf("%c", arr[row][col - 1]);
    }
}

int main(void)
{
    FILE* word = fopen("words.txt", "r");
    if (word == NULL)
        printf("Error: Could not open file!");

    char** arr;
    int r, c;

    fscanf(word, "%d %d", &r, &c);
    printf("The number of words: %d\n", r);
    printf("The word size: %d\n", c);

    arr = (char**)malloc(sizeof(char*) * r);

    for (int i = 0; i < r; i++)
        arr[i] = (char*)malloc(sizeof(char) * c);

    readFile(word, arr, r, c);
    displayWords(arr, r, c);
    displayWordsSpecCol(arr, r, c);

    for (int i = 0; i < r; i++)
        free(arr[i]);

    free(arr);

    fclose(word);

    return 0;
}