#include <stdio.h>

void hor_stair(int n, int total_steps);
void up_stair(int n, int total_steps);

void hor_stair(int n, int total_steps) {
    if (n > 0) {
        for (int i = 0; i < total_steps - n; i++) {
            printf("  ");
        }
        printf("__\n");
        up_stair(n, total_steps);
    }
}

void up_stair(int n, int total_steps) {
    if (n > 0) {
        for (int i = 0; i < total_steps - n; i++) {
            printf("  ");
        }
        printf("  |\n");
        hor_stair(n - 1, total_steps);
    }
}

int main() {
    int n;
    do {
        printf("Enter the number of steps: ");
        scanf_s("%d", &n);
    } while (n < 1);
    printf("\nHere is your staircase:\n\n");
    hor_stair(n, n);

    return 0;
}