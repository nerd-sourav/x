#include <stdio.h>

struct Student
{
    int roll;
    char name[20];
    float marks;
};

void main()
{
    struct Student s1;

    printf("Enter Details of the student");
    scanf("%d %s %f", &s1.roll, s1.name, &s1.marks);
    printf("%d\n %s\n %f\n", s1.roll, s1.name, s1.marks);
}