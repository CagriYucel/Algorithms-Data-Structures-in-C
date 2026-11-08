#include <stdio.h>

int main(void)
{
	double arr[4][3] = { { 40.90, 62.71, 50.30 }, { 100.21, 80.97, 23.14 }, { 20.91, 97.2, 30.17 }, { 52.87, 70.84, 49.56 } };
	printf("%p\n", arr);
	printf("%p\n", (arr + 1));
	printf("%p\n", *(arr + 1));
	
	printf("%p\n", (*(arr) + 1));
	printf("%.2f\n", *(*(arr) + 1));
	printf("%2.f\n", *(*(arr + 1)));

	printf("%p\n", *(*(arr)+1) + 2);
	printf("%p\n", (*(arr + 1) + 2));
	printf("%p\n", *(*(arr + 1) + 2));

	return 0;
}