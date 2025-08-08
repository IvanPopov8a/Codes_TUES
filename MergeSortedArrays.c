#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        merged[k++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    printf("Enter the number of elements in the first array: ");
    scanf_s("%d", &size1);

    int arr1[100];

    printf("Enter %d elements in the first array: ", size1);
    for (int i = 0; i < size1; i++) {
        scanf_s("%d", &arr1[i]);
    }

    bubbleSort(arr1, size1);

    printf("Enter the number of elements in the second array: ");
    scanf_s("%d", &size2);

    int arr2[100];

    printf("Enter %d elements in the second array: ", size2);
    for (int i = 0; i < size2; i++) {
        scanf_s("%d", &arr2[i]);
    }

    bubbleSort(arr2, size2);

    int merged[200];  

    mergeSortedArrays(arr1, size1, arr2, size2, merged);

    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
