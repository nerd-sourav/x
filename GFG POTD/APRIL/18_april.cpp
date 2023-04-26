//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> help(Node* root,int target,int &ans){
        if(!root)return {1,0,0,INT_MAX,INT_MIN};
        vector<int> l = help(root->left,target,ans);
        vector<int> r = help(root->right,target,ans);
        if(root->data<=l[4] || root->data>=r[3])return {0,0,0,0,0};
        int sum = root->data+l[2]+r[2];
        int n = 1+l[1]+r[1];
        if(l[0]==1 && r[0]==1 && sum==target){
            ans=min(ans,n);
        }
        return {l[0]&r[0],n,sum,min(l[3],root->data),max(r[4],root->data)};
        
    }
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int ans = INT_MAX;
        vector<int> temp = help(root,target,ans);
        if(temp[0]==1 and temp[2]==target){
            ans=min(ans,temp[1]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends
