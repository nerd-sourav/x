#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;

    head->link->link = current;

    printf("%d\n", head->data);
    printf("%d\n", current->data);
    printf("%d\n", head->link->link->data);
}