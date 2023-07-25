//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
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


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
     if(root==NULL)
   {
       return {};
   }
   //Your code here
   
   Node *delim = (Node*)malloc(sizeof(Node));
   delim->data = -1;
   delim->left = NULL;
   delim->right = NULL;
   
   queue<Node*> Q;
   
   Q.push(root);
   Q.push(delim);
   vector<vector<int>> V;
   vector<int> tmp;
   while(!Q.empty())
   {
       Node *front = Q.front();
       if(front->data != -1) tmp.push_back(front->data);
       Q.pop();
       
       if(front->data == -1)
       {
           if(Q.size()> 0 && Q.front()->data!=-1) Q.push(delim);
           V.push_back(tmp);
           tmp.clear();
       }
       else
       {
           if(front->left) Q.push(front->left);
           if(front->right) Q.push(front->right);   
       }
   }
   if(tmp.size()>0) V.push_back(tmp);
   vector<int> ans;
   for(int i = 0;i<V.size();i++)
   {
       if(i%2 == 0)
       {
           reverse(V[i].begin(), V[i].end());
       }
       for(int j = 0;j<V[i].size();j++)
       {
           ans.push_back(V[i][j]);
       }
   }
   return ans;
}
