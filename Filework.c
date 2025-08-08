#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void izbor_na_file(char* filename);
void zapis_vuv_fail(const char* filename);
void chetene_ot_fail(const char* filename);
void dobavi_kum_fail(const char* filename);

int main() {
    char filename[100] = "";
    int c = 0;
    int choice = 1;

    do {
        system("cls");
        printf("%s 1. File selection\n", choice == 1 ? ">" : " ");
        printf("%s 2. Write in file\n", choice == 2 ? ">" : " ");
        printf("%s 3. Read from file\n", choice == 3 ? ">" : " ");
        printf("%s 4. Add to file \n", choice == 4 ? ">" : " ");
        printf("%s 5. Exit\n", choice == 5 ? ">" : " ");

        c = _getch();
        if (c == 0 || c == 224) {
            c = _getch();
            if (c == 72 && choice > 1) choice--;
            if (c == 80 && choice < 5) choice++;
        }

        if (c == 13) {
            system("cls");

            switch (choice) {
            case 1:
                izbor_na_file(filename);
                break;
            case 2:
                zapis_vuv_fail(filename);
                break;
            case 3:
                chetene_ot_fail(filename);
                break;
            case 4:
                dobavi_kum_fail(filename);
                break;
            case 5:
                printf("You exited the program.\n");
                return 0;
            }
        }
    } while (1);
    return 0;
}

void izbor_na_file(char* filename) {
    printf("Enter file name: ");
    fgets(filename, sizeof(filename), stdin);
    char* newline = strchr(filename, '\n');
    if (newline) *newline = '\0';
    system("pause");
}

void zapis_vuv_fail(const char* filename) {
    FILE* file = fopen(filename, "w");
    int rows = 100;
    char row[100];
    if (!file) {
        printf("Error");
        return;
    }
    else {
        while (1) {
            fgets(row, sizeof(row), stdin);
            if (strcmp(row, "exit\n") == 0) {
                break;
            }
            if (strlen(row) > 1) {
                fprintf(file, "%s", row);
            }
            else {
                printf("Empty line, please enter some text.\n");
            }
        }
        fclose(file);
    }
}

void chetene_ot_fail(const char* filename) {
    FILE* file = NULL;
    char temp[256];

    if (fopen_s(&file, filename, "r") != 0) {
        printf("Error opening file.\n");
        return;
    }

    printf("Content of file:\n");
    while (fgets(temp, sizeof(temp), file)) {
        printf("%s", temp);
    }

    fclose(file);
    printf("\nPress any key to continue...\n");
    _getch();
}


void dobavi_kum_fail(const char* filename) {
    FILE* file = fopen(filename, "a");
    int rows = 100;
    char row[100];
    if (!file) {
        printf("Error");
        return;
    }
    else {
        while (1) {
            fgets(row, sizeof(row), stdin);
            if (strcmp(row, "exit\n") == 0) {
                break;
            }
            if (strlen(row) > 1) {
                fprintf(file, "%s", row);
            }
            else {
                printf("Empty line, please enter some text.\n");
            }
        }
        fclose(file);
    }
}