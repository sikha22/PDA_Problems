//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

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
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
      Node *curr=head;
        unordered_set<int> s;
        while(curr!=NULL)
        {
            s.insert(curr->data);
            curr=curr->next;
        }
        
        curr=head;
        Node *ans=new Node(9);
        Node *temp=ans;
        while(curr!=NULL)
        {
            if(s.find(curr->data)!=s.end())
            {
                Node *temp1=new Node(curr->data);
                s.erase(curr->data);
                temp->next=temp1;
                temp=temp->next;
            }
            
       
            curr=curr->next;
        }
        
        temp=ans;
        ans=ans->next;
        delete temp;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends
