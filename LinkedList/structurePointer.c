#include <stdio.h>

struct Student
{
    int roll;
    char name[20];
    float marks;
};

void main()
{
    struct Student s1 = {1, "Sourav", 99.99};

    struct Student *ptr = &s1;

    printf("\n%d %s %f", ptr->roll, ptr->name, ptr->marks);
    printf("\n%d %s %f", (*ptr).roll, (*ptr).name, (*ptr).marks);
    //     printf("Enter Details of the student");
    //     scanf("%d %s %f", &s1.roll, s1.name, &s1.marks);
    //     printf("%d\n %s\n %f\n", s1.roll, s1.name, s1.marks);
    //
}