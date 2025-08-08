#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int num;
    char name[80];
    int marks[20];
    float avr;
} Tstudent;

void my_change(char*);
void my_write(char*);
void my_read(char*);
void my_add(char*);


void main()
{
    int c = 0, op = 1;
    unsigned char c;
    char filename[80];
    my_change(filename);
    while (1)
    {
        system("cls");
        if (op == 1)printf(">1. FILE NAME\n");else printf(" 1. FILE NAME\n");//izvejdane na menu
        if (op == 2)printf(">2. WRITE\n");    else printf(" 2. WRITE\n");//izvejdane na menu
        if (op == 3)printf(">3. READ\n");     else printf(" 3. READ\n");//izvejdane na menu
        if (op == 4)printf(">4. ADD\n");      else printf(" 4. ADD\n");//izvejdane na menu
        if (op == 5)printf(">5. EXIT\n");     else printf(" 5. EXIT\n");//izvejdane na menu

        c = _getch();
        if (c == 224)
        {
            c =_getch();
            if (c == 72) { op--;if (op < 1)op = 5; }
            else if (c == 80) { op++;if (op > 5)op = 1; }
        }
        else if (c == 13)
        {
            c = op;
            if (c == 5)break;
            switch (c)
            {
            case 1: my_change(filename);break;
            case 2: my_write(filename);break;
            case 3: my_read(filename);break;
            case 4: my_add(filename);break;
            }
        }
    }
}

void my_read(char* filename)
{
    FILE* f;
    Tstudent s;
    int i = 0;
    if (f = fopen_s(filename,10000, "r"))
    {
        while (!feof(f))
        {
            if (fread(&s, sizeof(s), 1, f))
            {
                printf("%-3d%-20s", s.num, s.name);
                for (i = 0;s.marks[i];i++)printf("%-3d", s.marks[i]);
                printf("%-6.2f\n", s.avr);
            }
        }
        fclose(f);
    }
    else printf("ERROR OPEN FILE FOR READING!");
    printf("\nPress a key to continue...");
}

void my_write(char* filename)
{
    FILE* f;

    Tstudent s;

    char* p;
    char yes = 'Y';
    int i = 0, j;

    if (f = fopen_s(filename,10000, "r"))
    {
        printf("File exists! Overwrite Y/N?");
        scanf("%c", &yes);
        fclose(f);
    }
    if (yes != 'Y')return;

    if (f = fopen(filename, "w"))
    {
        while (1)
        {
            printf("Num:");scanf("%d", &s.num);
            getchar();
            if (s.num == 0)break;
            i++;
            printf("Name:");fgets(s.name, 80, stdin);
            if (p = strchr(s.name, '\n'))*p = '\0';
            j = 0; s.avr = 0;
            while (1)
            {
                printf("Mark %d Student %d:", j + 1, i);
                scanf_s("%d", &s.marks[j]);
                if (s.marks[j] == 0)break;
                s.avr += s.marks[j];
                j++;
            }
            if (j > 0)s.avr = s.avr / j;
            fwrite(&s, sizeof(s), 1, f);
        }
        fclose(f);
    }
    else printf("ERROR OPEN FILE FOR WRITING!");
}


void my_change(char* filename)
{
    printf("Filename:");
    fgets(filename, 80, stdin);
    char* p = strchr(filename, '\n');
    if (p)*p = '\0';
}

void my_add(char* filename)
{
    FILE* f;
    Tstudent s;
    char* p;
    int i = 0, j;
    if (f = fopen(filename, "a"))
    {
        while (1)
        {
            printf("Num:");
            scanf_s("%d", &s.num);
            getchar();
            if (s.num == 0)break;
            i++;
            printf("Name:");fgets(s.name, 80, stdin);
            if (p = strchr(s.name, '\n'))*p = '\0';
            j = 0; s.avr = 0;
            while (1)
            {
                printf("Mark %d Student %d:", j + 1, i);
                scanf_s("%d", &s.marks[j]);
                if (s.marks[j] == 0)break;
                s.avr = s.avr + s.marks[j];
                j++;
            }
            if (j > 0)s.avr = s.avr / j;
            fwrite(&s, sizeof(s), 1, f);
        }
        fclose(f);
    }
    else printf("ERROR OPEN FILE FOR APPENDING!");
}