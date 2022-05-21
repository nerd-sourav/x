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

        printf("%d->", temp->data);
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
void append()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node)); // mem allocated
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter data: ");
    scanf("%d", &temp->data);
    // new node created;
    // append means add only at the end;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}
void appendAtLoc()
{
    int loc, i = 1;
    printf("Enter locations: ");
    scanf("%d", &loc);

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node)); // mem allocated
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter data: ");
    scanf("%d", &temp->data);

    if (loc == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        struct Node *p = head;
        while (i < loc - 1)
        {
            p = p->next;
            i++;
        }

        temp->next = p->next;
        p->next->prev = temp;

        p->next = temp;
        temp->prev = p;
    }
}
void deleteAnyNode()
{
    int loc;
    printf("Enter Location: ");
    scanf("%d", &loc);

    if (loc == 1)
    {
        // deleting the first node;
        // 1.break connection of the second node;
        // 2.move head to second node;
        // 3.break conndecion of second node frm the first node;
        // 4.free the node

        struct Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        int i = 1;

        struct Node *prevNode, *currentNode;
        prevNode = NULL;
        currentNode = head;
        while (i < loc)
        {

            prevNode = currentNode;
            currentNode = currentNode->next;

            i++;
        }
        prevNode->next = currentNode->next;
        currentNode->next = NULL;

        free(currentNode);
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
        case 0:
            append();
            break;
        case 1:
            appendAtLoc();
            break;
        case 2:
            display();
            break;
        case 3:
            deleteAnyNode();
            break;
        case 7:
            exit(1);

        default:
            printf("Invalid operation\n");
            break;
        }
    }
}