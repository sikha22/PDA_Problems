//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod = 1000000007;
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m) {
        if(r < 0 or c < 0 or r >= n or c >= m or grid[r][c] == 0) return 0;
        
        if(r == n - 1 and c == m - 1) return 1;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        return dp[r][c] = (dfs(r + 1, c, grid, dp, n, m) % mod + dfs(r, c + 1, grid, dp, n, m) % mod) % mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(0, 0, grid, dp, n, m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
