#include<stdio.h>
#include<string.h>

#define MAX_SIZE 20

typedef struct {
	int num;
	char name[MAX_SIZE];
	int makrs[MAX_SIZE];
	float avr;
} Tstudent;

void main() {
	Tstudent students[MAX_SIZE];
	int n, i, j;
	float sum;
	int* p;
	
	do {
		printf("Enter the number of students: ");
		scanf_s("%d", &n);
	} while (n <= 0 || n > MAX_SIZE);
	getchar(); 
	for (i = 0; i < n; i++) {
		printf("Enter student number: ");
		scanf_s("%d", &students[i].num);
		getchar(); 
		printf("Enter student name: ");
		fgets(students[i].name, MAX_SIZE, stdin);
		if (p = strchr(students[i].name, '\n')) *p = '\0'; 
		printf("Enter marks for 3 subjects: ");
		for (j = 0; j < 3; j++) {
			scanf_s("%d", &students[i].makrs[j]);
		}
		sum = 0;
		for (j = 0; j < 3; j++) {
			sum += students[i].makrs[j];
		}
		students[i].avr = sum / 3.0;
	}
	printf("\nStudent Details:\n");
	for (i = 0; i < n; i++) {
		printf("Number: %d, Name: %s, Marks: %d %d %d, Average: %.2f\n",
			students[i].num, students[i].name,
			students[i].makrs[0], students[i].makrs[1], students[i].makrs[2],
			students[i].avr);
	}
}