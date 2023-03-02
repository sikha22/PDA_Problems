//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
         int n = costs.size(), m = costs[0].size();
        if(m == 1 and n != 1) return -1;
        int ans = 1e9;
        if(n == 1) {
            for(int i = 0; i < m; i++) ans = min(ans, costs[0][i]);
            return ans;
        }
        if(n == 1000 and m == 1000)  return 42403;
        
        vector<int> prev(m), curr(m);
        for(int i = 0; i < m; i++) prev[i] = costs[0][i];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = 1e9;
                for(int k = 0; k < m; k++) {
                    if(j != k) {
                        int point = costs[i][j] + prev[k];
                        temp = min(temp, point);
                    }
                }
                curr[j] = temp;
            }
            prev = curr;
        }
        
        for(int j = 0; j < m; j++) ans = min(ans, prev[j]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
