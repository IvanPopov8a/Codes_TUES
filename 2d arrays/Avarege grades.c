#include<stdio.h>
#define MAX_st 30
#define MAX_sub 20

void main() {
	int marks[MAX_st][MAX_sub], i, j, n, m;
	float avg[MAX_sub], sum, totalclass = 0;
	do {
		printf("Enter the number of students (1-%d): ", MAX_st);
		scanf_s("%d", &n);
	} while (n < 1 || n > MAX_st);
	do {
		printf("Enter the number of subjects (1-%d): ", MAX_sub);
		scanf_s("%d", &m);
	} while (m < 1 || m > MAX_sub);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			do {
				printf("Enter marks for student %d in subject %d (2-6): ", i + 1, j + 1);
				scanf_s("%d", &marks[i][j]);
			} while (marks[i][j] < 2 || marks[i][j] > 6);
		}
	}
	for (j = 0; j < m; j++) {
		sum = 0;
		for (i = 0; i < n; i++) {
			sum += marks[i][j];
		}
		avg[j] = sum / n;
	}
	for (i = 0; i < n; i++) {
		printf("Marks of student %d: ", i + 1);
		for (j = 0; j < m; j++) {
			printf("%d ", marks[i][j]);
		}
		printf("\n");
	}
	printf("Subject");
	for (j = 0; j < m; j++) {
		printf("   %3d   ", j + 1);
	}
	printF("\n");
	for (i = 0; i < n; i++) {
		printf(" Student : %3d   |", i + 1);
		float total = 0;
		for (j = 0; j < m; j++) {
			printf("   %3d   ", marks[i][j]);
			total += marks[i][j];
		}
		printf("  %.2f \n", total / m);
	}
	for (i = 0; i < n; i++) {
		float total = 0;
		for (j = 0; j < m; j++) {
			total += marks[i][j];
		}
		totalclass += total / m;
	}

	printf(" Average:           ");
	for (j = 0; j < m; j++) {
		printf("   %.2f  ", avg[j]);
	}
	printf(" %.2f \n", totalclass / n);
}