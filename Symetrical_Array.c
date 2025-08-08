#include <stdio.h>

#define Max_Elements 30

int Sym_Check(int Sym_ar[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (Sym_ar[i] != Sym_ar[n - 1 - i]) {
            return 0; 
        }
    }
    return 1; 
}

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

    if (Sym_Check(Sym_ar, n)) {
        printf("The array is symmetrical.\n");
    }

    else {
        printf("The array is not symmetrical.\n");
    }

    return 0;
}
