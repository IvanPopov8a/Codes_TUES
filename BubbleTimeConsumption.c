#include<stdio.h>
#define Max_Elements 10000

void main() {
	int Bubble[Max_Elements];
	int n,sw_count = 0;
	do {
		printf("Enter the number of elements (max %d): ", Max_Elements);
		scanf_s("%d", &n);
	} while (n < 1 || n > Max_Elements);
	for (int i = 0; i < n; i++) {
		printf("Enter the element %d: ", i + 1);
		scanf_s("%d", &Bubble[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int swapped = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (Bubble[j] < Bubble[j + 1]) {
				int temp = Bubble[j];
				Bubble[j] = Bubble[j + 1];
				Bubble[j + 1] = temp;
				swapped = 1;
				sw_count++;
			}
		}
		if (!swapped) {
			break;
		}
	}
	printf("Sorted array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Bubble[i]);
	}
	printf("\n");
	printf("Number of swaps: %d\n", sw_count);
}