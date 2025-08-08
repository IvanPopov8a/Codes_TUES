//ax^2+bx+c=0

#include<stdio.h>
#include<math.h>

int kvuravnenie(float, float, float, float*, float*);

void main()
{
    float a, b, c, x1, x2;
    printf("a=");
    scanf_s("%f", &a);
    printf("b=");
    scanf_s("%f", &b);
    printf("c=");
    scanf_s("%f", &c);
    switch (kvuravnenie(a, b, c, &x1, &x2))
    {
    case 1:printf("Every x");break;
    case 2:printf("No solution");break;
    case 3:printf("x=%.2f", x1);break;
    case 4:printf("N.R.K.");break;
    case 5:printf("x1=%.2f  x2=%.2f", x1, x2);break;
    }
}

int kvuravnenie(float a, float b, float c, float* px1, float* px2)
{
    float D;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)return 1;
            else return 2;
        }
        else
        {
            *px1 = -c / b;
            return 3;
        }
    }
    else
    {
        D = b * b - 4 * a * c;
        if (D < 0)return 4;
        else
        {
            *px1 = (-b + sqrt(D)) / (2 * a);
            *px2 = (-b - sqrt(D)) / (2 * a);
            return 5;
        }
    }
}
