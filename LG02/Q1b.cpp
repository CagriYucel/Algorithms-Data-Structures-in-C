#include <stdio.h>

int main(void)
{
	int arr[9] = { 30, 19, 11, 21, 80, 102, 966, 816, 54 };

	printf("%p\n", arr);
	printf("%p\n", arr + 2);
	printf("%d\n\n", *(arr + 2));

	printf("%d\n", *arr + 4);
	printf("%p\n", arr + 5);
	printf("%d\n", *(arr + 7));

	return 0;
}