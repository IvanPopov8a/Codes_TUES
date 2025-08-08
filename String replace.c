#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 200

int main() {
    char search[MAX_STRING_SIZE];
    char replace[MAX_STRING_SIZE];
    char ReplaceWith[MAX_STRING_SIZE];
    char* p;
    char* q;
    char buffer[MAX_STRING_SIZE * 2];
    int count = 0;

    printf("Enter a string: ");
    fgets(search, MAX_STRING_SIZE, stdin);
    if ((p = strchr(search, '\n'))) {
        *p = '\0';
    }

    printf("Enter the string to search for: ");
    fgets(replace, MAX_STRING_SIZE, stdin);
    if ((q = strchr(replace, '\n'))) {
        *q = '\0';
    }

    if (strlen(replace) == 0) {
        printf("The string to search for is empty.\n");
        return 1;
    }
    if (strlen(search) == 0) {
        printf("The string to search in is empty.\n");
        return 1;
    }

    printf("Enter the new substring: ");
    fgets(ReplaceWith, MAX_STRING_SIZE, stdin);
    if ((q = strchr(ReplaceWith, '\n'))) {
        *q = '\0';
    }

    int index = 0;
    char* current = search;

    while ((p = strstr(current, replace)) != NULL) {
        
        while (current < p) {
            buffer[index++] = *current++;
        }

        for (int i = 0; i < strlen(ReplaceWith); i++) {
            buffer[index++] = ReplaceWith[i];
        }

        current += strlen(replace);
        count++;
    }

    while (*current) {
        buffer[index++] = *current++;
    }

    buffer[index] = '\0'; 

    printf("Modified string: %s\n", buffer);
    printf("The string '%s' was found %d times.\n", replace, count);

    return 0;
}
