//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	     vector<pair<int,int>> arr;
	    int n = nums.size();
	    for(int i = 0;i<n; i++){
	        arr.push_back({nums[i], i});
	    }
	    sort(arr.begin(), arr.end());
	    int res = 0;
	    map<int, int> mp;
	    vector<int> vis(n);
	    for(int i =0;i<n;i++){
	        if(arr[i].second!=i){
	            mp[arr[i].second] = i;
	        }
	        else{
	            vis[i] = 1;
	        }
	    }
	    for(int i = 0;i<n;i++){
	        if(vis[i]==0){
	            int tt=mp[i], pp=i, start=i; 
	            while(start!=tt){
	                vis[tt]=1; vis[pp]=1;
	                pp = tt; tt = mp[pp];
	                res++;
	            }
	            vis[i] = 1;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
