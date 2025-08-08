#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 200

int main() {
	char look[MAX_STRING_SIZE];
	char find[MAX_STRING_SIZE];
	char* p;
	char* q;
	int count = 0;

	printf("Enter a string: ");
	fgets(look, MAX_STRING_SIZE, stdin);
	if (p = strchr(look, '\n')) {
		*p = '\0';
	}

	printf("Enter the string to search for: ");
	fgets(find, MAX_STRING_SIZE, stdin);
	if (q = strchr(find, '\n')) {
		*q = '\0';
	}
	if (strlen(find) == 0) {
		printf("The string to search for is empty.\n");
		return 1;
	}
	if (strlen(look) == 0) {
		printf("The string to search in is empty.\n");
		return 1;
	}

	p = look;
	while ((p = strstr(p, find)) != NULL) {
		count++;
		p += strlen(find);
	}

	printf("The string '%s' occurs %d times in '%s'.\n", find, count, look);
}