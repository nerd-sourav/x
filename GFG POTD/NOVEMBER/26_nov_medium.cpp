

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

class Solution
{
public:
    // function to construct tree from string

    int valid_path(int s, int e, string str)
    {
        if (s > e)
            return -1;

        stack<char> st;
        for (int i = s; i <= e; i++)
        {
            if (str[i] == '(')
                st.push(str[i]);
            else if (str[i] == ')')
            {
                st.pop();
                if (st.size() == 0)
                    return i;
            }
        }
        return -1;
    }
    Node *treeFromString(string str)
    {
        // code here
        return solve(0, str.size() - 1, str);
    }

    Node *solve(int s, int e, string str)
    {
        if (s > e)
            return NULL;

        //
        int num = 0;
        while (s < str.size() && isdigit(str[s]))
        {
            num = num * 10 + str[s] - '0';
            s++;
        }

        // node
        Node *root = new Node(num);
        int index = -1;

        if (s <= str.size() && str[s] == '(')
            index = valid_path(s, e, str);

        if (index != -1)
        {
            root->left = solve(s + 1, index - 1, str);
            root->right = solve(index + 2, e - 1, str);
        }
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends