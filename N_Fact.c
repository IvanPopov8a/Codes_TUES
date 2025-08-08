#include<stdio.h>
int fact1(int n)
{
	int P = 1, i;
	for (i = 1;i <= n;i++)P = P * i;
	return P;
}
int fact2(int n)
{
	if (n == 0)return 1;
	else return n * fact2(n - 1);
}
void main()
{
	int n;
	printf("n=");
	scanf_s("%d", &n);
	printf("\n%d", fact1(n));
	printf("\n%d", fact2(n));
}