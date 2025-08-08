#include <stdio.h>

int fib(int n);
int fib_min(int n);
int fib_max(int n);

int main() {
    int n;
    do {
        printf("n=?(n>0): ");
        scanf_s("%d", &n);
    } while (n < 1);

    printf("\nfib(%d) = %d", n, fib(n));
    printf("\nfib_min(%d) = %d", n, fib_min(n));
    printf("\nfib_max(%d) = %d\n", n, fib_max(n));

    return 0;
}
int fib(int n) {
    if (n == 1 || n == 2)
        return 1;

    int a = 1, b = 1, c = 1, i;
    for (i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int fib_min(int n) {
    int a = 1, b = 1, c = 1;
    while (c < n) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int fib_max(int n) {
    if (n <= 1) return 1; 

    int a = 1, b = 1, c = 1;
    while (c <= n) {
        a = b;
        b = c;
        c = a + b;
    }
    return b; 
}
