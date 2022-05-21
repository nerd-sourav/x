
#include <stdio.h>
#include <stdlib.h>
// creating a structure
// 1->2->3->4->5->6->7

struct Node
{
    int data;
    struct Node *next;
};

void insertNode(struct Node *tail, int element, int d)
{
    // if the list is empty;

    if (tail == NULL)
    {
        // create node then
        struct Node *newNode;
        newNode->data = d;
        newNode->next = NULL;
        tail = newNode;
        newNode->next = newNode;
        // first node inserted;
    }
    else
    {
        // assuming  few elements are already present in the list
        struct Node *current = tail;
        while (current->data != element)
        {
            current = current->next;
        }
        // element found
        struct Node *temp;
        temp->data = d;
        temp->next = NULL;

        temp->next = current->next;
        current->next = temp;
    }
}
void print(struct Node *tail)
{
    struct Node *temp = tail;
    do
    {
        printf("%d ", tail->data);
        tail = tail->next;
    } while (tail != temp);
}
int main()
{
    struct Node *tail = NULL;
    // list is empty;
    insertNode(tail, 5, 3);

    print(tail);
    insertNode(tail, 3, 13);

    print(tail);
    return 0;
}