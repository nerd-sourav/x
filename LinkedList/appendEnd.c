#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL; // head pointer
int main()
{
}
void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    {
        temp = root;
    }
    else
    {
        struct node *p;
        p = temp;
        while (p->link != NULL)
        {
            p->link = p;
        }
        p->link = temp;
    }
}