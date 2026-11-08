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
	printf("The drone info:\n");
	printf("Drone ID: %d\n", my_drone.droneID);
	printf("Price: %.2f\n", my_drone.price);
	printf("Size: %c\n", my_drone.size);
	
	return 0;
}