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


 void markParent(Node * root, unordered_map < Node * , Node * > & mp, int t, Node * & target) {
      if (!root) return;
      queue < Node * > q;
      q.push(root);
      while (!q.empty()) {

        int n = q.size();
        for (int i = 0; i < n; i++) {
          Node * root = q.front();
          q.pop();
          if (root -> data == t) target = root; //only for getting target node form given key
          if (root -> left) {
            mp[root -> left] = root; //  root k left ka parent root mark kr diya
            q.push(root -> left);
          }
          if (root -> right) {
            mp[root -> right] = root; // root k right ka parent root mark kr diya 
            q.push(root -> right);
          }
        }
      }
    }
class Solution{

    public:
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        unordered_map < Node * , Node * > parent_track;
        Node * target = new Node();
        markParent(root, parent_track, home, target);

        unordered_map < Node * , bool > visited;

        queue < Node * > q;

        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        vector < int > res;
        while (!q.empty()) {
          int sz = q.size();
          if (curr_level++ == k) break;
          for (int i = 0; i < sz; i++) {
            Node * curr = q.front();
            res.push_back(curr -> data);
            q.pop();
            if (curr -> left && !visited[curr -> left]) {
              q.push(curr -> left);
              visited[curr -> left] = true;
            }

            if (curr -> right && !visited[curr -> right]) {
              q.push(curr -> right);
              visited[curr -> right] = true;
            }

            if (parent_track[curr] and !visited[parent_track[curr]]) {
              q.push(parent_track[curr]);
              visited[parent_track[curr]] = true;
            }
          }
        }

        while (!q.empty()) {
          Node * curr = q.front();
          q.pop();
          res.emplace_back(curr -> data);
        }
        int ans = accumulate(begin(res), end(res), 0);
        return ans;
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
