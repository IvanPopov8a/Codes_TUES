#include<stdio.h>
#include<string.h>

#define MAX_STRING_SIZE 200

int main() {
	char string[MAX_STRING_SIZE];
	char* p;
	int br = 1;
	int longest = 0;
	char current_element;
	printf("Enter a string: ");
	fgets(string, MAX_STRING_SIZE, stdin);
	if (p = strchr(string, '\n')) {
		*p = '\0';
	}
	if (strlen(string) == 0) {
		printf("The string to search in is empty.\n");
		return 1;
	}
	for (int i = 1;string[i] != '\0';i++) {
		if (string[i - 1] == string[i]) {
			br++;
		}
		else {
			if (br > longest) {
				longest = br;
				current_element = string[i - 1];
			}
			br = 0;
		}
	}
	printf("The longest sequence of identical characters is %d.\n", longest + 1);
	printf("The character is '%c'.\n", current_element);
	return 0;
}