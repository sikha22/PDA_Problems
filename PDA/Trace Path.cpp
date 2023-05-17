//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
          int i = 0;
        int x = 0, y = 0;
        int minx = 0, miny = 0;
        int maxx = 0, maxy = 0;
        
        for(char d:s){
            switch (d){
                case 'R':
                x++;
                break;
                
                case 'L':
                x--;
                break;
                
                case 'D':
                y++;
                break;
                
                case 'U':
                y--;
                break;}
                
                minx = min(minx, x);
                miny = min(miny, y);
                
                maxx = max(maxx, x);
                maxy = max(maxy, y);
        }
        return ((maxx-minx < m) && (maxy-miny < n)); 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
