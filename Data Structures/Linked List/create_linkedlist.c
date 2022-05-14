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
    struct node *temp, *newnode;
    // memory  allocated
    newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    // we have now head and we have to perform operatuions on that
    // checking if the list is empty or not

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}
void main()
{

    int choice;

    printf("1 : Append\n");

    printf("Enter Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        append();
        break;

    default:
        break;
    }
}