#include<stdio.h>
#define Max_el 10

int main() {
	int Str[Max_el], min, i, n, k;
	do {
		printf("Enter number of elements max %d: ", Max_el);
		scanf_s("%d", &n);
		if (n < 1 || n > Max_el)
			printf("Elements must be 10 or lower");
	} while (n < 1 || n > Max_el);
	for (i = 0; i < n; i++) {
		printf("Enter element %d: ", i + 1);
		scanf_s("%d", &Str[i]);
	}
	for (i = 0; i < n - 1;i++) {
		min = Str[i];
		int mini = i;
		for (k = i + 1; k < n; k++) {
			if (Str[k] < min) {
				min = Str[k];
				mini = k;
			}
		}
		Str[mini] = Str[i];
		Str[i] = min;
	}
	printf("Sorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", Str[i]);
	}
	printf("\n");
	return 0;
}