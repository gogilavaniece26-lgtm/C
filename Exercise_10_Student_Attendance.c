#include <stdio.h>

struct Student
{
    int rollno;
    char name[50];
    char attendance;
};

int main()
{
    struct Student s[50];
    FILE *fp;
    int n, i;
    int present = 0, absent = 0;

    printf("===== STUDENT ATTENDANCE SYSTEM =====\n");
    printf("Enter the number of students: ");

    if (scanf("%d", &n) != 1 || n <= 0 || n > 50)
    {
        printf("Invalid number of students. Enter a value from 1 to 50.\n");
        return 1;
    }

    printf("\nEnter student details:\n");

    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll Number: ");
        if (scanf("%d", &s[i].rollno) != 1)
            return 1;

        printf("Name: ");
        if (scanf("%49s", s[i].name) != 1)
            return 1;

        printf("Attendance (P/A): ");
        if (scanf(" %c", &s[i].attendance) != 1)
            return 1;

        if (s[i].attendance == 'P' || s[i].attendance == 'p')
        {
            s[i].attendance = 'P';
            present++;
        }
        else if (s[i].attendance == 'A' || s[i].attendance == 'a')
        {
            s[i].attendance = 'A';
            absent++;
        }
        else
        {
            printf("Invalid attendance. Enter P or A.\n");
            return 1;
        }
    }

    /* Writing attendance into file */
    fp = fopen("attendance.txt", "w");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(fp, "===== ATTENDANCE REPORT =====\n");
    fprintf(fp, "Roll No\tName\tAttendance\n");

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d\t%s\t%c\n",
                s[i].rollno, s[i].name, s[i].attendance);
    }

    fprintf(fp, "\nTotal Present = %d\n", present);
    fprintf(fp, "Total Absent = %d\n", absent);

    fclose(fp);

    /* Displaying attendance report */
    printf("\n===== ATTENDANCE REPORT =====\n");
    printf("Roll No\tName\tAttendance\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%c\n",
               s[i].rollno, s[i].name, s[i].attendance);
    }

    printf("\nTotal Present = %d\n", present);
    printf("Total Absent = %d\n", absent);
    printf("\nAttendance saved successfully.\n");

    return 0;
}
