//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    bool isValid(int x,int y,int n,int m){
        if(x >= 0 && x < n && y >= 0 && y < m) return (true);
        return (false);
    }
    
    bool possible(int x,int y,vector<vector<char>> &grid,string &word,int ind,int dr){
        if(ind == word.size()) return (true);
        
        int n = grid.size(), m = grid[0].size();
        if(!isValid(x,y,n,m)) return (false);
        
        if(grid[x][y] != word[ind]) return (false);
        
        bool res = possible(x + dx[dr],y + dy[dr],grid,word,ind+1,dr);
        return (res);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	         int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == word[0]){
                    
                    for(int k = 0; k < 8; k++){
                        if(possible(i,j,grid,word,0,k)){
                            ans.push_back(vector<int>{i,j});
                            break;
                        }
                    }
                    
                }
            }
        }
        
        return (ans);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
