#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double ales;
	double yds;
} exam_t;

typedef struct {
	exam_t e;
	char name[MAX];
	double cgpa;
	double over;
	int sch;
} stu_t;

void calcScholarship(stu_t* s, int n)
{
	(s + n)->over = (s + n)->cgpa / 4 + (s + n)->e.ales / 2 + (s + n)->e.yds / 4;
	if ((s + n)->over >= 90)
		(s + n)->sch = 100;
	else if ((s + n)->over >= 80)
		(s + n)->sch = 75;
	else if ((s + n)->over >= 65)
		(s + n)->sch = 50;
	else
		(s + n)->sch = 0;
}

void readFromFile(FILE* stus, stu_t* s, int n)
{
	int i = 0;
	while (i < n)
	{
		fscanf(stus, "%s %lf %lf %lf", (s + i)->name,
			&(s + i)->cgpa,
			&(s + i)->e.ales,
			&(s + i)->e.yds);

		calcScholarship(s, i);
		i++;
	}
}

void displayRep(stu_t* s, int n)
{
	int i;
	printf("STUDENT NAME  CGPA   ALES   YDS   OVERALL SCHOLARSHIP PERCENTAGE\n");
	printf("************  ****   ****   ***   ******* **********************\n");

	for (i = 0; i < n; i++)
	{
		printf("%-12s %5.2f %5.2f %5.2f %8.2f %7d\n", (s + i)->name,
			(s + i)->cgpa,
			(s + i)->e.ales,
			(s + i)->e.yds,
			(s + i)->over,
			(s + i)->sch);
	}
}

int main(void)
{
	FILE* stus = fopen("graduateStudents.txt", "r");
	if (stus == NULL)
		printf("Error!");

	else {
		int n;
		fscanf(stus, "%d", &n);

		stu_t* s = (stu_t*)malloc(sizeof(stu_t) * n);
		printf("There are %d students in the Graduate program", n);

		readFromFile(stus, s, n);
		displayRep(s, n);
	}
	return 0;
}