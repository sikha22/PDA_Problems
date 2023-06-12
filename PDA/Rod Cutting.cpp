//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int cal(int i ,int len, int n , int*price , vector<vector<int>>&dp)
  {
     if(len==0)
      return 0 ;
      
      if(len<0)
      return -1e9 ;
      
       if(i==n)
      {
          if(len==0)return 0 ;
          return -1e9 ;
      }
      
      if(dp[i][len]!=-1)
      return dp[i][len] ;
      
      
      
      int take = 0 ,nottake=0 ;
      take = price[i] + max( cal(i, len - (i+1) , n,  price ,dp ) , cal(i+1, len-(i+1) , n ,price ,dp ) ); 
      nottake = cal(i+1, len , n , price ,dp ) ; 
      
      return dp[i][len] = max(take, nottake ); 
      
      
  }
 
    int cutRod(int price[], int n) {
        //code here
         vector<vector<int>>dp(n+1 ,vector<int>(n+1, -1 )) ;
        return cal(0 ,n ,  n,  price ,dp ); 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
