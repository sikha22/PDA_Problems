//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
         long long int ans=0;
 for(int i=0;i<K;i++)
     ans+=GeekNum[i];
     
 GeekNum.push_back(ans);
         
 int j = K;
 for(int i=K+1;i<N;i++){
     long long int temp = GeekNum[i-1]-GeekNum[i-K-1]+GeekNum[i-1];
  GeekNum.push_back(temp);   
 }
 return GeekNum[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
