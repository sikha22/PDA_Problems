//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
          const int M = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(r+1,0));
        for(int i = 0;i <= r;i++){
            dp[0][i] = 0;
        }
        for(int i = 0;i <= n;i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n;i++){
            for(int j = 1;j <= r;j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%M;
            }
        }
        dp[n][r] = (dp[n-1][r] + dp[n-1][r-1])%M;
        return dp[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends
