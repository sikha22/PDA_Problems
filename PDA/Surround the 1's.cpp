//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
         int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(matrix[i][j] == 1){
        
                    int ct = 0;
                    for(int x = -1; x<2; x++){
                        for(int y = -1; y<2; y++){
                            if(x == 0 && y == 0) continue;
                            int nx = x + i;
                            int ny = y + j;
                            if(nx >= 0 && nx < n && ny >=0 && ny < m && matrix[nx][ny] == 0) ct++; 
                        }
                    }
                    
                    if(ct > 0 && ct % 2 == 0) ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
