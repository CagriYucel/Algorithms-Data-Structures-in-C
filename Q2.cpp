#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define SIZE 3

int main(void)
{
	FILE* res = fopen("result.txt", "w");
	if (res == NULL)
		printf("Error!");

	else {
		int r, c, arr[SIZE][SIZE], cnt = 1;
		
		for(r = 0; r < SIZE; r++)
			for (c = 0; c < SIZE; c++)
			{
				*(*(arr + r) + c) = pow(4, cnt);
				cnt++;
			}
		
		fprintf(res, "Element name\t\t Value\t Address\n-------------------- ----- --------\n");
		
		for(r = 0; r < SIZE; r++)
			for (c = 0; c < SIZE; c++)
			{
				fprintf(res, "*(*(arr + %d) + %d)\t", r, c);
				fprintf(res, "%6d", *(*(arr + r) + c));
				fprintf(res, "\t%p\n", (*(arr + r) + c));
			}
		
		printf("Successful! Please see the result.txt file for the output.");
	}
	
	return 0;
}