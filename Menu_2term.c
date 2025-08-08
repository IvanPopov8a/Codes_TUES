#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#define Max_student 100
#define Max_name 20
#define Max_marks 30


void alphabetical_sort(char[][Max_name], int n);
void sort_by_average(char[][Max_name], float[], int n);
void scholarship(char[][Max_name], int n, float[]);
void F_students(char[][Max_name], int n, float[]);



int main() {

    char names[Max_student][Max_name];
    float average[Max_student];
    int marks[Max_student][Max_marks];
    int n, m;
    int* p;
    int c = 0, choice = 1;
    int i, j;

    do {
        printf("Enter number of students (1-%d): ", Max_student);
        scanf_s("%d", &n);
    } while (n < 1 || n > Max_student);
    do {
        printf("Enter number of subjects (1-%d): ", Max_marks);
        scanf_s("%d", &m);
    } while (m < 1 || m > Max_marks);
    getchar();
    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        fgets(names[i], Max_name, stdin);
        if (p = strchr(names[i], '\n')) *p = '\0';
    }
    for (i = 0; i < n; i++) {
        printf("Enter marks for %s: ", names[i]);
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("Mark %d: ", j + 1);
            scanf_s("%d", &marks[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        average[i] = 0;
        for (j = 0; j < m; j++) {
            average[i] += marks[i][j];
        }
        average[i] /= m;
    }
    do {
        system("cls");
        printf("%s 1. Alphabetical order\n", choice == 1 ? ">" : " ");
        printf("%s 2. Average sort\n", choice == 2 ? ">" : " ");
        printf("%s 3. Scholarship\n", choice == 3 ? ">" : " ");
        printf("%s 4. F students \n", choice == 4 ? ">" : " ");
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
            case 1: {
                alphabetical_sort(names, n);
                break;
            }
            case 2: {
                sort_by_average(names, average, n);
                break;
            }
            case 3: {
                scholarship(names, n, average);
                break;
            }
            case 4: {
                F_students(names, n, average);
                break;
            }
            case 5: {
                return 0;
            }
            }
        }
    } while (1);
    return 0;
}

void scholarship(char names[][Max_name], int n, float average[Max_student]) {
    printf("\nStudents with scholarship:\n");
    for (int i = 0; i < n; i++) {
        if (average[i] >= 5.5) {
            printf("%s\n", names[i]);
        }
    }
    system("pause");
}
void sort_by_average(char names[][Max_name], float average[Max_student], int n)
{
    char temp[Max_name];
    float temp_avg;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (average[i] < average[j]) {
                temp_avg = average[i];
                average[i] = average[j];
                average[j] = temp_avg;
                strcpy_s(temp, Max_name, names[i]);
                strcpy_s(names[i], Max_name, names[j]);
                strcpy_s(names[j], Max_name, temp);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s - %.2f\n", names[i], average[i]);
    }
    system("pause");
}
void alphabetical_sort(char names[][Max_name], int n) {
    char temp[Max_name];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy_s(temp, Max_name, names[i]);
                strcpy_s(names[i], Max_name, names[j]);
                strcpy_s(names[j], Max_name, temp);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }
    system("pause");
}

void F_students(char names[][Max_name], int n, float average[Max_student]) {
    printf("\nInventors:\n");
    for (int i = 0; i < n; i++) {
        if (average[i] < 2.0) {
            printf("%s\n", names[i]);
        }
    }
    system("pause");
}