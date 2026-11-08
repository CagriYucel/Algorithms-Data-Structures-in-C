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

	FILE* dr = fopen("drones.txt", "r");
	if (dr == NULL)
		printf("Error!");

	else {
		int a, i;
		fscanf(dr, "%d", &a);
		printf("There are %d drones", a);
		printf("The drone list:\n");

		drone_t* drones = (drone_t*)malloc(sizeof(drone_t) * a);

		for (i = 0; i < a; i++)
		{
			fscanf(dr, "%d", &(drones + i)->droneID);
			fscanf(dr, "%lf", &(drones + i)->price);
			fscanf(dr, " %c", &(drones + i)->size);
		}

		for (i = 0; i < a; i++)
		{
			printf("*******************\n");
			printf("Drone id: %d\n", (drones + i)->droneID);
			printf("Price: %.2f\n", (drones + i)->price);
			printf("Size: %c\n", (drones + i)->size);
		}
	}
	fclose(dr);

	return 0;
}