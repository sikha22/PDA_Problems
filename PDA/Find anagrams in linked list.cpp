//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    
    bool isAnagram(string a, string b){
        sort(begin(b),end(b));
        return a == b;
    }
    
    void addToVector(string t, vector<Node *> &res){
        Node *ans = new Node(0);
        Node *temp = ans;
        
        for(int i=0; i<t.length(); i++){
            Node *newNode = new Node(t[i]);
            temp->next = newNode;
            temp = newNode;
        }
        
        res.push_back(ans->next);
    }
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        sort(begin(s),end(s));
        Node *temp = head;
        
        vector<Node *> res;
        string t = "";
        while(temp != NULL){
            t += temp->data;
            
            if(s.length() == t.length()){
                if(isAnagram(s,t)){
                    addToVector(t,res);
                    t = "";
                }
                else{
                    t = t.substr(1);
                }
            }
            
            temp = temp->next;
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends
