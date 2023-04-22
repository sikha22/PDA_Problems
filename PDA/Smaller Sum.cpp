//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
          long long sum = 0;
        priority_queue<int> pq;
        
        for(int i = 0;i<n;i++){
            sum += arr[i];
            pq.push(arr[i]);
        }
        
        vector<long long> ans;
        unordered_map<long long, long long> mp;
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            sum -= x;
            mp[x] = sum;
        }
        
        for(int i = 0;i<n;i++){
            ans.push_back(mp[arr[i]]);
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
