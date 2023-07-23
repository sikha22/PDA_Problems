//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
        struct Node* reverse(struct Node *head){
        if(head==NULL){
            return head;
        }
        struct Node * prev=NULL, *temp=head, *curr=head;
        while(temp){
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
          struct Node *slow=head, *fast=head, *a=NULL, *no_change, *noc;
        struct Node *a_prev=NULL;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        a = reverse(slow->next);
        no_change=a;
        noc=head;
        slow->next=NULL;
        while(a){
            a=a->next;
            if(a->next==NULL){
                a->next=head;
                break;
            }
        }
        a=no_change;
        while(a!=noc){
            a->data=a->data-head->data;
            head=head->next;
            a_prev=a;
            a=a->next;
        }
        a_prev->next=reverse(a);
        return no_change;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends
