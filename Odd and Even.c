#include <stdio.h>

int main() {
    int n, i,arr[40], even[40], odd[40], evenCount = 0, oddCount = 0;
    printf("Enter number of elements(Max 40): ");
    scanf_s("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);

        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        }
        else {
            odd[oddCount++] = arr[i];
        }
    }

       printf("Even elements: ");
    for (i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
    
    printf("Odd elements: ");
    for (i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}
