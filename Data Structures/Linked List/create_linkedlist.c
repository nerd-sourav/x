#include <stdio.h>
#include <stdlib.h>
// creating a structure
// 1->2->3->4->5->6->7

struct node
{
    int data;
    struct Node *link;
};
struct node *head = NULL;
void append()
{

    // the node which need to be added
    struct node *temp;
    // memory  allocated
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &temp->data);

    // we have now head and we have to perform operatuions on that
    // checking if the list is empty or not
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *point;
        point = head;
        while (point->link != NULL)
        {
            point = point->link;
        }
        point->link = temp;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->link;
        }
    }
}
int main()
{

    int choice;
    while (1)
    {
        printf("1 : Append\n");
        printf("2 : Display\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            append();
            break;
        case 2:
            display();
            break;
        default:
            printf("Invalid operation\n");
            break;
        }
    }
}