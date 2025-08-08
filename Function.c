#include <stdio.h>
#define Max_Elements 10
void change(int *pArr1, int *pArr2,int *pswapped) {
    int temp = *pArr1;
    *pArr1 = *pArr2;
    *pArr2 = temp;
    *pswapped = 1;
}

int main() {
    int Bubble[Max_Elements];
    int n;

    do {
        printf("Enter the number of elements (max %d): ", Max_Elements);
        scanf_s("%d", &n);
    } while (n < 1 || n > Max_Elements);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &Bubble[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (Bubble[j] < Bubble[j + 1]) {
                change(&Bubble[j], &Bubble[j + 1], &swapped );
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

    return 0;
}
