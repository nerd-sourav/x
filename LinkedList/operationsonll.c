/* performing operations on a linkedlist */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
// head also as root;
struct node *root = NULL;
int len = 0;
void append();
void addbegin();
void addafter();
int length();
void display();
void delete ();
int main()
{
    int ch;
    while (1)
    {
        printf("\nSingle linked list operations: \n\n");
        printf("1. Append at end    2. Add at begin\n");
        printf("3. Add after        4. Length\n");
        printf("5. Display all      6. Delete\n");
        printf("7. Quit\n\n");

        printf("Enter your choice: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            addbegin();
            break;
        case 3:
            addafter();
            break;
        case 4:
            len = length();
            printf("length is: %d\n", len);
            break;
        case 5:
            display();
            break;
        case 6:
            delete ();
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    // temperory node is created with two fields

    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    // List is empty, only root available
    {
        root = temp; // this start to point to the 1st node of the list
        // first node is inserted.
    }
    // after adding the first node , to add next node
    else
    {
        struct node *p;
        p = root;
        while (p->link != NULL) // check wether next node is available
        {
            p = p->link;
        }
        p->link = temp;
    }
}
void addbegin(void)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    temp->link = root;
    root = temp;
}
void addafter(void)
{
    struct node *temp, *p;
    int i = 1, loc, len = length();
    printf("Enter location: \n");
    scanf("%d", &loc);
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d", &temp->data);

    if (loc > len)
    {
        printf("Invalid Location\n");
    }
    else
    {
        p = root;
        while (i < loc)
        {
            p = p->link;
            i++;
        }
        // right side connection
        temp->link = p->link;
        p->link = temp;
    }
}
int length(void)
{
    int count = 0;
    struct node *temp;
    temp = root;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}
void display(void)
{
    struct node *temp;
    temp = root;
    if (root == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-> ", temp->data);
            temp = temp->link;
        }
    }
}
void delete (void)

{
    struct node *temp;
    temp = root;

    int loc;
    printf("Enter locaton: ");
    scanf("%d", &loc);
    if (loc > length())
    {
        printf("Invalid Location\n");
    }
    else if (loc == 1)
    {
        temp = temp->link;
        root = temp;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node *p = root, *q;
        int i = 1;
        while (i < loc - 1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}

void reverse()
{
    Struct
}