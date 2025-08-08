#include<stdio.h>
#define Max_el 10000

sw_count = 0;	

void arr_input(int, int);
void arr_output(int, int);
void straight_insertion(int, int);

void main() {
	int n, a[Max_el];
	printf("Enter the number of elements: ");
	scanf_s("%d", &n);
	arr_input(a, n);
	straight_insertion(a, n);
	arr_output(a, n);
}

void arr_input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Enter the element %d: ", i + 1);
		scanf_s("%d", &a[i]);
	}
}

void arr_output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("Number of swaps: %d\n", sw_count);
}

void straight_insertion(int a[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
		sw_count++;
	}
}
