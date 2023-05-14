//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
  long long solve(vector<int> &A, int idx, bool prev, vector<vector<int>>& dp){
        if(idx >= A.size()) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        long long ans;
        if(prev == false){
            ans = max(solve(A, idx+1, true, dp), A[idx] + solve(A, idx+1, false, dp));
        }
        else{
            ans = A[idx] + solve(A, idx+1, false, dp);
        }
        return dp[idx][prev] = ans;
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<int>> dp(N, vector<int>(2, -1));
        return solve(A, 0, false, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
