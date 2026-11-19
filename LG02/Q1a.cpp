#include <stdio.h>

int main(void)
{
	int x = 55, y;
	int* ptrX = &x;
	int* ptrY;
	*ptrX = x + 3;
	y = *ptrX + 10;
	ptrY = ptrX;
	*ptrX = x + y;

	printf("%p\n", &x);
	printf("%p\n", &y);
	printf("%p\n\n", ptrX);

	printf("%d\n", *ptrX);
	printf("%d\n", x);
	printf("%p\n\n", ptrY);
	
	printf("%d\n", *ptrY);
	printf("%p\n", ptrX + 4);
	printf("%d\n\n", (*ptrX + 4));

	return 0;
}