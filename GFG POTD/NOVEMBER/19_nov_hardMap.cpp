#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        // Base Cases
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;

        queue<Node *> q1, q2;

        // push the root node
        q1.push(root1);
        q2.push(root2);

        while (q1.size() > 0 && q2.size() > 0)
        {
            // size represent the size of current level
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2)
                return false;

            vector<int> v1, v2;
            // level order q1
            while (n1 > 0)
            {
                Node *front1 = q1.front();
                q1.pop();

                v1.push_back(front1->data);

                // push the children
                if (front1->left != NULL)
                    q1.push(front1->left);
                if (front1->right != NULL)
                    q1.push(front1->right);
                n1--;
            }
            while (n2 > 0)
            {
                Node *front2 = q2.front();
                q2.pop();

                v2.push_back(front2->data);
                // push the children
                if (front2->left != NULL)
                    q2.push(front2->left);
                if (front2->right != NULL)
                    q2.push(front2->right);
                n2--;
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            if (v1 != v2)
                return false;
        }
        if (q1.empty() && q2.empty())
            return true;
        return false;
    }
};

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends