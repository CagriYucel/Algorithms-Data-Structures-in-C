#define _CRT_SECURE_NO_WARNINGS
#define MAX 300
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* t = fopen("tennisLong.txt", "r");
	if (t == NULL)
		printf("Error!");

	else {
		FILE* outp = fopen("output.txt", "w");
		char arr[MAX];
		int i, cnt = 0, max = 0, b, len, arr2[MAX] = { 0 };

		while (fscanf(t, "%s", arr) != EOF && cnt < MAX)
		{
			len = strlen(arr);
			arr2[len]++;
			cnt++;

			if (max < len)
				max = len;
		}
		fclose(t);
		fprintf(outp ,"Word length Occurrences\n----------------------------\n");

		for (i = 0; i < cnt; i++)
		{
			if(arr2[i] != 0)
				fprintf(outp, "%5d %10d\n", i, arr2[i]);
		}
	}
	return 0;
}