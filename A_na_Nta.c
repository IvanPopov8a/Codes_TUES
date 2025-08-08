#include<stdio.h>
  float nta1(float a, int n) {
	 float ans = 1,m;
     if (n < 0) {
         m = -n;
     }
     if (n > 0) {
         m = n;
     }
     for (int i = 0;i < m;i++) {
         ans = ans * a; 
     }
     if (n < 0) {
         ans = 1 / ans;
}
	 return ans;
 }
 float nta2(float a, int n) {
	 if (n == 0) return 1;
     else if (n > 0) {
		 return a * nta2(a, --n );
	 }
	 else {
		 return 1 / a * nta2(a, ++n );
 }
     }
 void main() {
	 int a, n;
	 printf("Enter a number: ");
	 scanf_s("%d", &a);
	 printf("Enter the power: ");
	 scanf_s("%d", &n);
	 printf("The result is: %f\n", nta1(a, n));
	 printf("The second result is: %f\n", nta2(a, n));
 }