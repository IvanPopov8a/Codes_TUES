#include <stdio.h>
#include <string.h>

#define MAX_SIZE 250

int isBalanced(const char* str) {
    int stack = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            stack++;
        }
        else if (str[i] == ')') {
            if (stack == 0)
                return 0;
            stack--;
        }
    }

    return stack == 0;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string of brackets (max 250 characters): ");
    if (fgets(str, MAX_SIZE, stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    if (isBalanced(str)) {
        printf("The brackets are balanced.\n");
    }
    else {
        printf("The brackets are not balanced.\n");
    }

    return 0;
}