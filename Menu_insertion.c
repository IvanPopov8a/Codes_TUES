#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Required for _getch()

#define Max_el 10

void arr_input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf_s("%d", &a[i]);
    }
}

void straight_insertion(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

void straight_selection(int a[], int n) {
    int i, j, k, temp;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

void bubble_sort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void arr_output(int a[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {  // Standard return type for main()
    int n, a[Max_el], choice = 1;
    char c;

    do {
        system("cls");
        printf("%s 1. Straight Insertion\n", choice == 1 ? ">" : " ");
        printf("%s 2. Straight Selection\n", choice == 2 ? ">" : " ");
        printf("%s 3. Bubble Sort\n", choice == 3 ? ">" : " ");
        printf("%s 4. Exit\n", choice == 4 ? ">" : " ");

        c = _getch();
        if (c == 72 && choice > 1) choice--; 
        if (c == 80 && choice < 4) choice++; 

        if (c == 13) {  
            system("cls");

            if (choice == 4) return 0;  
            
            do {
                printf("Enter the number of elements (1 to %d): ", Max_el);
                scanf_s("%d", &n);
                if (n < 1 || n > Max_el) {
                    printf("Invalid input! Please enter a number between 1 and %d.\n", Max_el);
                }
            } while (n < 1 || n > Max_el);

            arr_input(a, n);

            switch (choice) {
            case 1:
                straight_insertion(a, n);
                break;
            case 2:
                straight_selection(a, n);
                break;
            case 3:
                bubble_sort(a, n);
                break;
            }

            arr_output(a, n);
            printf("\nPress any key to return to menu...");
            _getch();
        }

    } while (1);

    return 0;
}
