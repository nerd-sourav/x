//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    void reorderList(Node *head)
    {
        // Your code here
        // step 1 - using slow and fast pointer
        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // step 2 -  split the List into two.
        Node *List1 = head;                // 1 2 3
        Node *List2 = reverse(slow->next); // 4 5
        slow->next = NULL;

        // step 3 - merging the two list and second list can be shorter
        while (List2)
        {
            Node *temp1 = List1->next;
            Node *temp2 = List2->next;
            List1->next = List2;
            List2->next = temp1;
            List1 = temp1;
            List2 = temp2;
        }
    }

    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nxt = NULL;

        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};

//{ Driver Code Starts.

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    int t, n, m, i, x;

    cin >> t;
    while (t--)
    {
        struct Node *temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        Solution ob;

        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends
