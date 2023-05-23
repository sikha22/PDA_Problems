//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
      Node* solve(vector<int> pre, vector<int> preMirror, int n){
        if(n==0)return NULL;
        Node* root = new Node(pre[0]);
        
        
        //left side
        vector<int> lpre, lpreMirror;
        
        for(int i=1;i<n;i++){
            if(pre[i]==preMirror[1])break;
            lpre.push_back(pre[i]);
        }
        int flag=0;
        for(int i=1;i<n;i++){
            if(preMirror[i]==pre[1])flag=1;
            if(flag)lpreMirror.push_back(preMirror[i]);
        }
        
        //right side
        vector<int> rpre, rpreMirror;
        
        for(int i=1;i<n;i++){
            if(preMirror[i]==pre[1])break;
            rpreMirror.push_back(preMirror[i]);
        }
        flag=0;
         for(int i=1;i<n;i++){
            if(pre[i]==preMirror[1])flag=1;
            if(flag)rpre.push_back(pre[i]);
        }
        
        root->left = solve(lpre,lpreMirror,lpre.size());
        root->right = solve(rpre,rpreMirror,rpre.size());
        return root;
        
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
         vector<int> preV(size),preMirrorV(size);
        for(int i=0;i<size;i++)preV[i]=pre[i],preMirrorV[i]=preMirror[i];
        return solve(preV,preMirrorV,size);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
