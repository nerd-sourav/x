#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{

    struct node *head, *newnode, *tempnode;
    head = 0;

    int choice = 10;
    while (1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode = tempnode;
        }
        else
        {
            tempnode->next = newnode;
            newnode = tempnode;
        }
        choice--;
    }
}
