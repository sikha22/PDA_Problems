//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
         for(int i=0;i<N;i++) {

            for(int j=0;j<3;j++) {

                if(i==0) {

                    continue;

                }

                if(j==0){

                colors[i][j]=colors[i][j]+min(colors[i-1][j+1],colors[i-1][j+2]);

                }

                else if(j==1) {

                    colors[i][j]=colors[i][j]+min(colors[i-1][j-1],colors[i-1][j+1]); 

                }

                else{

                     colors[i][j]=colors[i][j]+min(colors[i-1][j-1],colors[i-1][j-2]);

                }

            }

        }

        return min(colors[N-1][0],min(colors[N-1][1],colors[N-1][2]));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
