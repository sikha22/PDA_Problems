//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        long long int mod = 1000000007;
        long long int ans = 0;
        long long int sec = 1;
        long long int first = 0;
        for(int i=2; i<=n; i++){
            ans = (first+sec)%mod;
            first = sec;
            sec = ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
