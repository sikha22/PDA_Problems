//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
          vector<vector<int>> ans;
         sort(intervals.begin(),intervals.end());
         stack<vector<int>> st;
         
         for(auto it: intervals)
         {
             if(st.size()==0)
             st.push(it);
             
             vector<int> pre = st.top();
             
             if(pre[1]<it[0])
             st.push(it);
             else
             {
                 st.pop();
                 pre[1] = max(pre[1],it[1]);
                 st.push(pre);
             }
         }
         
         while(st.size()>0)
         {
             ans.push_back(st.top());
             st.pop();
         }
         
         sort(ans.begin(),ans.end());
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
