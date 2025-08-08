#include<stdio.h>
void main() {
	float Grades[30],avg=0,all=0;
	int n,p=1,i,st_sum=1;
		do {
			printf("Enter the number of children: ");
			scanf_s("%d", &n);
			if (n <= 1 || n >= 30)
				printf("Invalid number of children. Please enter a number between 1 and 30.\n");
		} while (n <= 1 || n >= 30);

		for ( i = 0;i < n;i++) {
			do {
				printf("Enter the grade of child %d (2 to 6): ", st_sum + 1);
				scanf_s("%f", &Grades[i]);
				all += Grades[i];
			} while (Grades[i] < 2 || Grades[i] > 6);
		}
		avg = all / n;
		printf("\nAverage: %.2f\n", avg);
		 i = 0;
		while (i < n) {

			if (Grades[i] > 5.49) {
				printf("Student No%d is an excellent student.\n", p);
			}

			else if (Grades[i] < 2.50) {
				printf("Student No%d will not be going to the beach this summer.\n", p);
			}

			i++;
			p++;
		}
		
		
}