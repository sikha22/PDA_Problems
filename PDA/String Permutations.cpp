//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
     int fact(int n){
        if(n==0) return 1;
        else return n*fact(n-1);
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> res;
        int n = S.size();
        long long m = fact(n);
        for(int i=0;i<m;i++){
            next_permutation(S.begin(),S.end());
            res.push_back(S);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
