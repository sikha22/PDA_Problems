//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		     string ans="";
            set<char> st;
            map<char,int> mp;
            for(int i=0;i<A.length();i++){
                if(mp[A[i]]==0){
                    st.insert(A[i]);
                }else{
                    if(st.find(A[i])!=st.end()){
                        st.erase(st.find(A[i]));
                    }
                }
                if(mp[A[i]]==0)mp[A[i]]=i+1;
                char c='#';int t=INT_MAX;
                for(auto it:st){
                    if(mp[it]<t){
                        t=mp[it];
                        c=it;
                    }
                }
                ans+=c;
            }
            return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
