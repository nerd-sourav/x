//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    Node *king;                           // location of home
unordered_map<Node *, Node *> parent; // parent map
// Level Order Traversal to take the nodes level wise
int LevelOrder(int k)
{
    int sum = 0;
    queue<Node *> q;
    q.push(king);
    unordered_map<Node *, bool> vis;
    vis[king] = true;
    int steps = 0;
    while (!q.empty())
    {
        int qsize = q.size();
        while (qsize--)
        {
            auto curr = q.front();
            q.pop();
            sum += curr->data;
            if (curr->left && !vis[curr->left])
            {
                vis[curr->left] = true;
                q.push(curr->left);
            }
            if (curr->right && !vis[curr->right])
            {
                vis[curr->right] = true;
                q.push(curr->right);
            }
            if (parent[curr] && !vis[parent[curr]])
            {
                vis[parent[curr]] = true;
                q.push(parent[curr]);
            }
        }
        if (steps == k)
            break;
        steps++;
    }
    return sum;
}
// Find the home and make the parent map
void MakeParent(Node *root, int home)
{
    queue<Node *> q;
    q.push(root);
    parent[root] = NULL;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        // Searching the home
        if (curr->data == home)
        {
            king = curr;
        }
        if (curr->left)
        {
            q.push(curr->left);
            parent[curr->left] = curr;
        }
        if (curr->right)
        {
            q.push(curr->right);
            parent[curr->right] = curr;
        }
    }
}
int ladoos(Node *root, int home, int k)
{
    MakeParent(root, home);
    return LevelOrder(k);
}


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends
