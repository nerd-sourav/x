//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if (node == nullptr) return new Node(data);
        if (node->data > data) node->left = insertToAVL(node->left, data);
        if (node->data < data) node->right = insertToAVL(node->right, data);

        node->height = max(height(node->left), height(node->right)) + 1;
        int diff = height(node->left) - height(node->right);

        if (diff > 1) {
            if (data < node->left->data) return rightRotate(node);
            else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (diff < -1) {
            if (data > node->right->data) return leftRotate(node);
            else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }
    private:
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    Node* rightRotate(Node* node) {
        Node* l = node->left;
        Node* lr = l->right;
        l->right = node;
        node->left = lr;

        node->height = max(height(node->left), height(node->right)) + 1;
        l->height = max(height(l->left), height(l->right)) + 1;
        return l;
    }

    Node* leftRotate(Node* node) {
        Node* r = node->right;
        Node* rl = r->left;
        r->left = node;
        node->right = rl;

        node->height = max(height(node->left), height(node->right)) + 1;
        r->height = max(height(r->left), height(r->right)) + 1;

        return r;
    }

};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends
