#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int nta1(int a, int n) {
    int ans = 1, m;
    if (n < 0) {
        m = -n;
    }
    else {
        m = n;
    }
    for (int i = 0; i < m; i++) {
        ans *= a;
    }
    if (n < 0) {
        ans = 1 / ans;
    }
    return ans;
}

int nta2(int a, int n) {
    if (n == 0) return 1;
    else if (n > 0) return a * nta2(a, n - 1);
    else return 1 / (a * nta2(a, n + 1));
}

void hanoi(int n, char from_stack, char to_stack, char temp_stack) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_stack, to_stack);
        return;
    }
    hanoi(n - 1, from_stack, temp_stack, to_stack);
    printf("Move disk %d from %c to %c\n", n, from_stack, to_stack);
    hanoi(n - 1, temp_stack, to_stack, from_stack);
}

void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int k = 0; k < (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void fig(int n, char c) {
    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= n - k; j++) {
            printf("  ");
        }
        for (int j = 1; j <= k; j++) {
            printf("%c ", c);
        }
        printf("\n");
    }
}

void fig3(int n, char c) {
    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= n - k; j++) {
            printf("  ");
        }
        for (int j = 1; j <= k; j++) {
            printf("%c ", c);
        }
        printf("\n");
    }
}

void displayMenu() {
    int choice = 1;
    char c;
    do {
        system("cls");
        printf("%s 1. Power Calculation\n", choice == 1 ? ">" : " ");
        printf("%s 2. Hanoi Towers\n", choice == 2 ? ">" : " ");
        printf("%s 3. Pyramid 1\n", choice == 3 ? ">" : " ");
        printf("%s 4. Pyramid 2\n", choice == 4 ? ">" : " ");
        printf("%s 5. Pyramid 3\n", choice == 5 ? ">" : " ");
        printf("%s 6. Exit\n", choice == 6 ? ">" : " ");

        c = _getch();
        if (c == 72 && choice > 1) choice--; 
        if (c == 80 && choice < 6) choice++; 

        if (c == 13) { 
            system("cls");
            switch (choice) {
            case 1: {
                int a, n;
                printf("Enter a number: ");
                scanf_s("%d", &a);
                printf("Enter the power: ");
                scanf_s("%d", &n);
                printf("The result is: %d\n", nta1(a, n));
                printf("The result is: %d\n", nta2(a, n));
                break;
            }
            case 2: {
                int num_disks;
                printf("Enter number of disks: ");
                scanf_s("%d", &num_disks);
                hanoi(num_disks, 'A', 'B', 'C');
                break;
            }
            case 3: {
                int n;
                printf("Enter the number of lines for the pyramid: ");
                scanf_s("%d", &n);
                printPyramid(n);
                break;
            }
            case 4: {
                int n;
                char c;
                printf("Enter quantity of lines: ");
                scanf_s("%d", &n);
                getchar(); 
                printf("Enter character to be printed: ");
                scanf_s(" %c", &c, 1); 
                fig(n, c);
                break;
            }
            case 5: {
                int n;
                char c;
                printf("Enter quantity of lines: ");
                scanf_s("%d", &n);
                getchar(); 
                printf("Enter character to be printed: ");
                scanf_s(" %c", &c, 1); 
                fig3(n, c);
                break;
            }
            case 6:
                printf("Exiting...\n");
                exit(0);
            }
            printf("\nPress any key to return to the menu...\n");
            _getch();
        }
    } while (1);
}
int main() {
    displayMenu();
    return 0;
}