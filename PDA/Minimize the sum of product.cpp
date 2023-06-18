//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+n);
        vector<int> descending;
        for(int i=n-1;i>=0;i--){
            descending.push_back(b[i]);
        }
        for(int i=0;i<n;i++){
            b[i] = descending[i];
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans = ans + a[i] * b[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends
