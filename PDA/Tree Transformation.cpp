//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
         vector<int> deg(N,0);
        int res=0;
        
        for(int i=1;i<N;i++){     
            deg[i]++;                
            deg[p[i]]++;
        }
        
        for(int i=0;i<N;i++)    
            if(deg[i]>1)
                res++;
                res=res==0?res:res-1;
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends
