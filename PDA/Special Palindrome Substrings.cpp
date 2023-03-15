//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
      bool inRange(int val, pair<int, int>& range) {
        return range.first <= val && val <= range.second;
    }
    int specialPalindrome(string s1, string s2){
        //Code Here
        int n = s1.size();
        int m = s2.size();
        int res = INT_MAX;

        for(int st = 0; st <= n - m; st++) {
            int oper = 0;
            pair<int, int> changeRange = {st, st + m - 1};
            string copy = s1;
            for(int i = st; i <= st + m - 1; i++) {
                if(copy[i] != s2[i-st]) {
                    copy[i] = s2[i-st];
                    oper++;
                } 
            }
            bool ok = true;
            int start = 0, end = n - 1;
            while(start < end) {
                if(copy[start] == copy[end]) {
                    start++;
                    end--;
                } else {
                    if(inRange(start, changeRange) && inRange(end, changeRange)) {
                        ok = false;
                        break;
                    }
                    oper++;
                    start++;
                    end--;
                }
            }
            if(ok) {
                res = min(res, oper);
            }
        }

        return res == INT_MAX ? -1: res;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
