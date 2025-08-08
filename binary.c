#include <stdio.h>

void print_binary(int n) {
    if (n > 1) {
        print_binary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf_s("%d", &num);
    printf("Binary representation: ");
    print_binary(num);
    printf("\n");
    return 0;
}
