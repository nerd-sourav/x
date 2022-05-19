#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {

        printf("%d", &temp->data);
        temp = temp->next;
    }
}

int lenght()
{
    struct Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
}

int main()
{

    int choice;
    while (1)
    {
        printf("\n0 : Add at end \n");
        printf("1 : Add at any location\n");
        printf("2 : Display\n");
        printf("3 : Delete at any location\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        // case 0:
        //     append();
        //     break;
        // case 1:
        //     appendAtLoc();
        //     break;
        case 2:
            display();
            break;
        // case 3:
        //     deleteAtLoc();
        //     break;
        case 7:
            exit(1);

        default:
            printf("Invalid operation\n");
            break;
        }
    }
}