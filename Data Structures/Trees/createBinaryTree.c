#include <stdio.h>
#include <stdlib.h>
// changes made
// chanegs made
// cganges made
// changes made
// changea made
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node *));
    printf("Entr -1 for no node");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newNode->data = x;
    printf("Enter left child of %d", x);
    newNode->left = create();
    printf("Enter right child");
    newNode->right = create();
    return newNode;
}

int main()
{
    struct node *root = NULL;
    root = create();
}