#include<stdio.h>
void up_stair(int);
void hor_stair(int n) {
	if (n > 0) {
		printf("Flip\n");
		n--;
		up_stair(n);
	}
 }
void up_stair(int n) {
	if (n > 0) {
		printf("Flop\n");
		n--;
		hor_stair(n);
	}
}
void main() {
	int n;
	do{
	printf("Enter a number: ");
	scanf_s("%d", &n);
	} while (n < 1);
	hor_stair(n);
}	