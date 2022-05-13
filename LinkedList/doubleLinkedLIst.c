#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *head = NULL;
void append();
void display();
void main()
{
    // create a double linked list
    for (int i = 0; i < 5; i++)
    {
        append();
    }
    display();
}
void append()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data: ");
    scanf("%d", &temp->data);

    if (head == NULL) // no elements are present
    {
        head = temp;
    }
    else
    {
        struct Node *p;
        p = head;
        while (p->right != NULL)
        {
            p = p->right;
        }
        temp->left = p;
        p->right = temp;
    }
}

void display()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", &temp->data);
        temp = temp->right;
    }
}
void reverse()
{
}