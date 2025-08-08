#include <stdio.h>

int main() {
    float temps[10], sum = 0, avg;

    printf("Enter temperatures for 10 days:\n");
    for (int i = 0; i < 10; i++) {
        scanf_s("%f", &temps[i]);
        sum += temps[i];
    }

    avg = sum / 10;
    printf("\nAverage: %.2f\n", avg);

    for (int i = 0; i < 10; i++)
        printf("Day %d Amplitude: %.2f\n", i + 1, avg - temps[i]);

    return 0;
}
