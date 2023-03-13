//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long long ans = 0;
        int count = 0;
        int small = INT_MAX;
        
        for(int i=0;i<N;i++) {
            if(B[i] % 2 != 0) B[i]--;
            B[i] /= 2;
            if(B[i] > 0) {
                count += B[i];
                ans += (A[i] * B[i] * 2);
                small = min(small, A[i]);
            }
        }
        
        if(count % 2 != 0) ans -= (small * 2);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends
