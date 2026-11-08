#define _CRT_SECURE_NO_WARNINGS
#define MAX 5
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int englishProficiency, jury, graduateExam;
} grades_t;

typedef struct {
	int id;
	grades_t gr;
	double overall;
}app_t;

int readFile(FILE *a, app_t *arr)
{
	int i = 0;
	while (fscanf(a, "%d", &(arr + i)->id) != EOF)
	{
		fscanf(a, "%d", &(arr + i)->gr.englishProficiency);
		fscanf(a, "%d", &(arr + i)->gr.jury);
		fscanf(a, "%d", &(arr + i)->gr.graduateExam);
		i++;
	}

	return i;
}

void calc(app_t *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		(arr + i)->overall = ((arr + i)->gr.englishProficiency * 3.0 / 10 + (arr + i)->gr.jury / 2.0 + (arr + i)->gr.graduateExam / 5.0);
}

void display(app_t *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Applicant ID: %d\n\nScores:\n", (arr + i)->id);
		printf("Applicant English Proficiency: %d\n", (arr + i)->gr.englishProficiency);
		printf("Applicant Jury: %d\n", (arr + i)->gr.jury);
		printf("Applicant Graduate Examination: %d\n", (arr + i)->gr.graduateExam);
		printf("Applicant Overall: %.1f\n\n", (arr + i)->overall);
	}
}

void findPassFail(app_t *arr, int size)
{
	int i, p, f;
	double sum = 0, avg;
	p = f = 0;

	for (i = 0; i < size; i++)
		sum += (arr + i)->overall;

	avg = sum / size * 1.0;
	printf("Average is %.1f\n", avg);

	for (i = 0; i < size; i++)
	{
		if ((arr + i)->overall > avg)
			p++;
		else
			f++;
	}
	
	printf("Number of the applicants who pass is %d\n", p);
	printf("Number of the applicants who fail is %d\n", f);
}

int main(void)
{
	FILE* app = fopen("applicants.txt", "r");
	if (app == NULL)
		printf("Error!");

	else {
		int size;
		app_t* arr = (app_t*)malloc(sizeof(app_t) * MAX);

		size = readFile(app, arr);
		calc(arr, size);

		display(arr, size);
		findPassFail(arr, size);
	}
	return 0;
}