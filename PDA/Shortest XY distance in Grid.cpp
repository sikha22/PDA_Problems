//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
         vector<pair<int,int>>x, y;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j]=='X') x.push_back({i,j});
                else if(grid[i][j]=='Y') y.push_back({i,j});
            }
        }
        
        int ans=INT_MAX;
        for(auto a: x){
            for(auto b: y){
                int x1=a.first;
                int y1=a.second;
                int x2=b.first;
                int y2=b.second;
                
                if(abs(x1-x2)+abs(y1-y2)<ans){
                    ans=abs(x1-x2)+abs(y1-y2);
                }
                if(ans==1) return ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
