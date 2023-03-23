//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
int ans = -1;
    void solve(Node* root, int calSum, int target)
    {
        if(!root)
            return;
        
        if(root->data == target)
        {
            int fromLeaf = targetToLeaf(root);
            ans = calSum - fromLeaf + root->data;
            return;
        }
        
        else if(target > root->data)
            solve(root->right, root->data + calSum, target);

        else
            solve(root->left, root->data + calSum, target);
    }
    
    int targetToLeaf(Node* root)
    {
        if(!root)
            return 1e5;
        else if(!(root->left) && !(root->right))
            return root->data;
            
        int left = root->data + targetToLeaf(root->left);
        int right = root->data + targetToLeaf(root->right);
        
        return min(left, right);
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
         int calSum = 0;
        ans = -1;
        solve(root, calSum, target);
        
        if(ans == -1)
            return -1;
        else
            return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
