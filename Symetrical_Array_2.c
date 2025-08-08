#include<stdio.h>
#define Max_Elements 100
int main() {
	int Sym_ar[Max_Elements];
	int n;
	do {
		printf("Enter the number of elements (max %d): ", Max_Elements);
		scanf_s("%d", &n);
	} while (n < 1 || n > Max_Elements);
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &Sym_ar[i]);
	}
	int flag = 1;
	for (int i = 0; i < n / 2; i++) {
		if (Sym_ar[i] != Sym_ar[n - 1 - i]) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("The array is symmetrical.\n");
	}
	else {
		printf("The array is not symmetrical.\n");
	}
}