#include <stdio.h>
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

int main() {
    int n;
    char c;

    printf("Enter quantity of lines: ");
    scanf_s("%d", &n);
    getchar();
    printf("Enter character to be printed: ");
    scanf_s("%c", &c,1);
    fig(n, c);
    return 0;
}