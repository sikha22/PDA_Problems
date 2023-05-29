//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool findIt(string& pattern, string& CamelCaseString) {
        
        int i = 0, j = 0, n = pattern.length(), m = CamelCaseString.length();
        
        while(i < n and j < m) {
            if(pattern[i] == CamelCaseString[j])i++;
            else if(isupper(CamelCaseString[j]))return 0;
            j++;
        }
        
        return i == n ? 1 : 0;
    }
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string> res;
        
        for(auto &str: Dictionary) {
            if(findIt(Pattern,str))res.push_back(str);
        }
        
        if(res.empty())res.push_back("-1");
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
