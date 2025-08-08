#include<stdio.h>

void change(int* pa, int* pb)
{

    int c;
    c = *pa;
    *pa = *pb;
    *pb = c;
}

void main()
{
    int x , y ;
    int p , q;
	printf("x=");
	scanf_s("%d", &x);
	printf("y=");
	scanf_s("%d", &y);
	printf("p=");
	scanf_s("%d", &p);
	printf("q=");
	scanf_s("%d", &q);
    change(&x, &y);
    change(&p, &q);
    printf("\nx=%d y=%d", x, y);
    printf("\np=%d q=%d", p, q);
}