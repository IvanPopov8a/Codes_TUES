#include <stdio.h>

int main() {
	float temps[30], sum = 0, avg;
	int n;
	do {
		printf("Enter the number of days: ");
		scanf_s("%d", &n);
		if (n <= 1 || n >= 30)
			printf("Invalid number of days. Please enter a number between 1 and 30.\n");
	} while (n <= 1 || n >= 30);
	printf("Enter temperatures for %d days:\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%f", &temps[i]);
		sum += temps[i];
	}
	avg = sum / n;
	printf("\nAverage: %.2f\n", avg);

	for (int i = 0; i < n; i++)
		printf("Day %d Amplitude: %.2f\n", i + 1, temps[i] - avg);

	return 0;
}