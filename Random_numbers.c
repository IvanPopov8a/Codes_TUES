#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int digits, count;

    printf("Enter number of digits: ");
    if (scanf_s("%d", &digits) != 1 || digits < 1) {
        printf("Invalid input for digits.\n");
        return 1;
    }

    printf("Enter count of numbers: ");
    if (scanf_s("%d", &count) != 1 || count < 1) {
        printf("Invalid input for count.\n");
        return 1;
    }

    // Dynamically allocate memory for storing the random numbers
    int* numbers = (int*)malloc(count * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Set up the range based on number of digits
    unsigned int lower = 1, upper = 9;
    for (int i = 1; i < digits; i++) {
        lower *= 10;
        upper = upper * 10 + 9;
    }

    srand((unsigned int)time(NULL));

    // Generate random numbers
    for (int i = 0; i < count; i++) {
        numbers[i] = lower + rand() % (upper - lower + 1);
    }

    // Output the generated numbers
    printf("\nGenerated numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }

    // Clean up
    free(numbers);

    return 0;
}
