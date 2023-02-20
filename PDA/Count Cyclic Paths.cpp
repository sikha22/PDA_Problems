//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{ 
    private:
    int memo(int n, int O, vector<vector<int>> &dp)
    {
        if(n<=1)
            return 0;
        if(n==2)
        {
            if(O==1)
                return 3;
            else
                return 2;
        }
        
        if(dp[n][O]!=-1) return dp[n][O];
        
        int mod=1e9+7;
        if(O==1)
        {
            int temp= memo(n-1,0,dp)%mod;
            return dp[n][O] = (((2*temp)%mod)+temp)%mod;
        }
        else
        {
            int temp1=memo(n-1,0,dp)%mod;  
            int temp2=memo(n-1,1,dp)%mod;
            return dp[n][O] = (((2*temp1)%mod)+temp2)%mod;
        }
    }
public:
    int countPaths(int N){
        // code here 
         vector<vector<int>> dp(N+1, vector<int>(2,-1));
        return (memo(N,1,dp));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
