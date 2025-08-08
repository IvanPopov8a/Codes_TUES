#include<stdio.h>
#define MAX 10

void straight_insertion(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}


int search(int arr[], int n, int x) {
	int i;
	for (i = 0; i < n && arr[i] <= x; i++) {
		if (arr[i] == x) {
			return 1;
		}
	}
	return 0;
}

void input(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Enter element %d: ", i + 1);
		scanf_s("%d", &arr[i]);
	}
}
void output(int arr[], int n) {
	int i;
	printf("Array elements are: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void main() {
	int arr[MAX], n, x;
	printf("Enter number of elements in array: ");
	scanf_s("%d", &n);
	printf("Enter element to search: ");
	scanf_s("%d", &x);
	input(arr, n);
	straight_insertion(arr, n);
	if (search(arr, n, x)) {
		printf("Element %d found in the array.\n", x);
	}
	else {
		printf("Element %d not found in the array.\n", x);
	}
	output(arr, n);

}