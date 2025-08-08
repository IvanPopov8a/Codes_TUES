#include <stdio.h>

int main() {
    int n, i, arr[20];

    printf("Enter number of elements(Max 20): ");
    scanf_s("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("Elements in reverse order:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
