//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
         priority_queue<long long > pq;
        for(int i=0;i<N;i++)
        {
            pq.push(A[i]);
        }
        long long sum=0;
        for(int i=0;i<K;i++)
        {
         long long  val=pq.top();
            pq.pop();
            sum+=val;
            val=val/2;
            pq.push(val);
       
        }
    return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
