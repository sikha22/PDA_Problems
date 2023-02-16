//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
void dfs(vector<int>& arr, int i, int n, vector<int>& vis, int& flag){
        if(i<0 || i>=n || vis[i] == 2){
            flag = 2;
            return;
        }
        if(vis[i] == 1) return;
        vis[i] = 1;
        dfs(arr, i+arr[i], n, vis, flag);
        if(flag == 2) vis[i] = 2;
        if(flag == 0) vis[i] = 1; 
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> vis(n, false);
        int ans = 0;
        for(int i=0; i<n; i++){
            int flag = 0;
            dfs(arr, i, n, vis, flag);
        }
        for(int i=0; i<n; i++){
            if(vis[i] == 2)
                ans++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
