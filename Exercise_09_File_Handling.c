#include <stdio.h>

struct Student
{
    int rollno;
    char name[50];
    float mark;
};

union Contact
{
    char phone[15];
    char email[50];
};

int main()
{
    struct Student s;
    union Contact c;
    FILE *fp;
    char line[100];

    printf("Enter student roll number: ");
    if (scanf("%d", &s.rollno) != 1)
        return 1;

    printf("Enter student name: ");
    if (scanf("%49s", s.name) != 1)
        return 1;

    printf("Enter student mark: ");
    if (scanf("%f", &s.mark) != 1)
        return 1;

    printf("Enter phone number: ");
    if (scanf("%14s", c.phone) != 1)
        return 1;

    /* Writing data into file */
    fp = fopen("student.txt", "w");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(fp, "Roll Number : %d\n", s.rollno);
    fprintf(fp, "Name        : %s\n", s.name);
    fprintf(fp, "Mark        : %.2f\n", s.mark);
    fprintf(fp, "Phone       : %s\n", c.phone);

    fclose(fp);
    printf("\nStudent details written to file successfully.\n");

    /* Reading data from file */
    fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("\n----- STUDENT DETAILS -----\n");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
