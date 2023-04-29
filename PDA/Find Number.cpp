//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
         long digitPlace = 1; 
    long result = 0; 
    while (N > 0) { 
        N--; 
        result += ((2 * (N % 5)) + 1) * digitPlace;
        N = N / 5; 
        digitPlace *= 10; 
    }
    return result; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
