//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
vector<int>matching;
vector<int>vis;
 bool solve(int person,vector<vector<int>>&G){
     
     for(int job=0;job<G[0].size();job++){
         if(G[person][job]==1 and vis[job]==0){
             vis[job]=1;
             if(matching[job]==-1 or solve(matching[job],G)){
                 matching[job]=person;
                 return true;
             }
         }
     }
     return false;
 }
	int maximumMatch(vector<vector<int>>&G){
	    // Code here
	    int ans=0;
     int m=G.size(),n=G[0].size();
     matching=vector<int>(n,-1);
     
     for(int i=0;i<m;i++){
         vis=vector<int>(n,0);
         if(solve(i,G)){
             ans++;
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
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends
