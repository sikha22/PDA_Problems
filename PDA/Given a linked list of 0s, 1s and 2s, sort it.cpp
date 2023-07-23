//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        vector<Node*> point(6, NULL);
        
        Node* temp=head;
        
        while(temp!=NULL){
            int val=temp->data;
            if(point[val]==NULL){
                point[val]=temp;
                point[val+3]=temp;
            }else{
                point[val+3]->next=temp;
                point[val+3]=temp;
            }
            temp=temp->next;
            point[val+3]->next=NULL;
        }
        Node* ans=NULL;
        for(int i=0;i<3;i++){
            if(point[i]!=NULL){
                if(ans!=NULL){
                    if(point[i+2]!=NULL) point[i+2]->next=point[i];
                    else point[i+1]->next=point[i];
                }else{
                    ans=point[i];
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
