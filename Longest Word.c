#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 200

int main() {
    char string[MAX_STRING_SIZE];
    char longest_word[MAX_STRING_SIZE];
    int max_length = 0;

    printf("Enter a string: ");
    if (fgets(string, MAX_STRING_SIZE, stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    char* newline = strchr(string, '\n');
    if (newline) *newline = '\0';

    if (strlen(string) == 0) {
        printf("The string to search in is empty.\n");
        return 1;
    }

    int i = 0, start = 0, length = 0;

    while (1) {
        if (string[i] != ' ' && string[i] != '\0') {
            length++;
        }
        else {
            if (length > max_length) {
                max_length = length;
                char temp[MAX_STRING_SIZE];
                for (int j = 0; j < length; j++) {
                    temp[j] = string[start + j];
                }
                temp[length] = '\0';
                strcpy_s(longest_word, MAX_STRING_SIZE, temp);
            }
            length = 0;
            start = i + 1;
        }

        if (string[i] == '\0') break;
        i++;
    }

    if (max_length > 0) {
        printf("The longest word is \"%s\".\n", longest_word);
    }
    else {
        printf("No words found.\n");
    }

    return 0;
}
