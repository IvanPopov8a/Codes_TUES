#include<stdio.h>
#include<string.h>

int main() {
	char* p;
	char str[20];
	int len = 0, len2 = 0;
	printf("Enter a string: ");
	fgets(str, 19, stdin);
	if (p = strchr(str, '\n')) {
		*p = '\0';
	}
	len = strlen(str);
	for (int i = 0; str[i] != '\0'; i++) {
		len2++;
	}
	printf("Length of string using strlen: %d\n", len2);
	printf("Length of string: %d\n", len);
	printf("Size of string: %d\n", sizeof(str));

}