//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
          int pos=0;
     int lawda=0;
     int jump =0;
     int i=0;
     while(i<n-1&&pos<n-1)
     {
         if(i==pos&&arr[pos]==0&&pos==lawda)
         return -1;
         lawda=max(lawda,arr[i]+i);
         if(i==pos)
         {
             pos=lawda;
             jump++;
           
         }
         i++;
     }
     return jump;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
