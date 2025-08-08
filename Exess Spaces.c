#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 200

int main() {
    char string[MAX_STRING_SIZE];
    int i = 0, j = 0;
    int in_word = 0;

    printf("Enter a string with excess spaces: ");
    fgets(string, MAX_STRING_SIZE, stdin);

    char* newline = strchr(string, '\n');
    if (newline) *newline = '\0';

    
    while (string[i] == ' ') i++;

    while (string[i] != '\0') {
        if (string[i] == ' ') {
            if (in_word) {
                string[j++] = ' '; 
                in_word = 0;
            }
        }
        else {
            string[j++] = string[i];
            in_word = 1;
        }
        i++;
    }

    if (j > 0 && string[j - 1] == ' ') {
        j--;
    }

    string[j] = '\0'; 

    printf("Cleaned string: \"%s\"\n", string);

    return 0;
}
