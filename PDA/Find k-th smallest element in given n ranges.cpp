//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
         sort(range.begin(),range.end());


       vector<int>ans;


       int start=range[0][0];
       int end=range[0][1];
       
       vector<pair<int,int>>value;


       
       for(int i=1;i<n;i++){
           if(end>=range[i][0])
           end=max(end,range[i][1]);
           else{
               value.push_back({start,end});
               start=range[i][0];
               end=range[i][1];
           }
       }
       value.push_back({start,end});

       for(int i=0;i<q;i++){
           int num=queries[i];
           int flag=0;
           for(int j=0;j<value.size();j++){
               if(num<=value[j].second-value[j].first+1){
                   ans.push_back(value[j].first+num-1);
                   flag=1;
                   break;
               }
               else{
                   num-=value[j].second-value[j].first+1;
               }
           }
           if(!flag)
           ans.push_back(-1);
       }
       
       
       return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
