#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int droneID;
	double price;
	char size;
} drone_t;

int main(void)
{
	drone_t my_drone = { 1, 1499.99, 'S' };
	drone_t* drone;
	drone = &my_drone;
	printf("Enter the information of the drone:\n");
	
	printf("Drone ID: ");
	scanf("%d", &drone->droneID);

	printf("Price: ");
	scanf("%lf", &drone->price);

	printf("Size: ");
	scanf(" %c", &drone->size);

	printf("The drone info:\n");
	printf("Drone ID: %d\n", drone->droneID);

	printf("Price: %.2f\n", drone->price);
	printf("Size: %c\n", drone->size);

	return 0;
}