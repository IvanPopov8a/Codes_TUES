#include <stdio.h>
#include <string.h>

#define MAX_SIZE 250

int main() {
    char str[MAX_SIZE];
	int matched[MAX_SIZE];
    int pairs[MAX_SIZE][2]; 
    int top = -1;
    int count = 0;
    int *p,br;

    printf("Enter a string of brackets (max 250 characters): ");
    if (fgets(str, MAX_SIZE, stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }
    if (p = strchr(str, "\n")) {
		*p = '\0'; 
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ')') {
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '(' && matched[j] == 0) {
                    matched[j] = 1;
                    matched[i] = 1;
                    pairs[count][0] = j + 1;
                    pairs[count][1] = i + 1;
                    count++;
                    break;
                }
            }
        }
    }

    if (top != -1) {
        printf("The brackets are not balanced.\n");
        return 0;
    }

    printf("The brackets are balanced.\n");
    printf("List of bracket pairs (i,j):\n");
    for (int i = 0; i < count; i++) {
        printf("%d,%d\n", pairs[i][0], pairs[i][1]);
    }

    return 0;
}