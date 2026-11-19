#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 6

int main(void)
{
	FILE* res = fopen("result.txt", "w");
	int i, nums[MAX], j;
	int* a = &nums[0];

	fprintf(res, "Element Name    Value   Address\n-------------    -----   --------\n");

	for (i = 0; i < MAX; i++)
	{
		j = pow(6, i + 1);
		a = &nums[i];
		fprintf(res, "* (nums +    %d)", i);
		fprintf(res, "%7d", j);
		fprintf(res, "\t\t%p\n", a);
	}

	fclose(res);

	return 0;
}