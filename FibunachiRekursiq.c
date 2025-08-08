#include<stdio.h>
int i = 0;
int fib1(int n) {
	int a = 1, b = 1, c = 1;
	for (int i = 3;i <= n;i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int fib2(int n) {
	i++;
	if (n < 3)return 1;
	else return fib2(n - 1) + fib2(n - 2);
}

void main()
{
	int n;
	scanf_s("%d", &n);
	printf("\n%d", fib1(n));
	printf("\n%d", fib2(n));
	printf("\n%d", i);
}