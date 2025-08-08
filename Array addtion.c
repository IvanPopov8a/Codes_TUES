#include<stdio.h>
#define Max_Elements 30

int main() {
	int Array[Max_Elements];
	int n;
	int sum = 0;
	do {
		printf("Enter the number of elements (max %d): ", Max_Elements);
		scanf_s("%d", &n);
	} while (n < 1 || n > Max_Elements);
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &Array[i]);
	}
	for (int i = 0; i < n; i++) {
		if (Array[i] < 0) {
			break;
		}
		sum += Array[i];
	}
	printf("Sum of the array elements: %d\n", sum);
	return 0;
}