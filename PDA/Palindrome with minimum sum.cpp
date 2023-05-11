//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
         int n=s.size();
        for(int i=0; i<n/2; i++) 
        if (s[i]!=s[n-1-i] and (s[n-1-i]!='?' and s[i]!='?'))
        return -1;
        char ch;
        int ind=n;
        bool foundatlast=false;
        for(int i=0; i<=n/2; i++) {if (s[i]!='?') {ind=i; break;}}
        for(int i=n-1; i>=0; i--){
            if (s[i]!='?'){
                
                if (ind>n-1-i){
                    ind = min(ind, n-1-i);
                    foundatlast = true;
                }
                break;
            }
        }
        if (foundatlast) ch = s[n-1-ind];
        else ch = s[ind];
        if (ind==n) ch='a';
        for(int i=0; i<n/2; i++){
            if ((s[i]=='?' and s[n-1-i]!='?')) {s[i]=s[n-1-i], ch=s[n-1-i];}
            else if ((s[i]!='?' and s[n-1-i]=='?')) {s[n-1-i] = s[i], ch=s[i];}
            else if (s[i]!='?' and s[n-1-i]!='?') ch=s[i];
            else {
                s[i]=ch;
                s[n-1-i]=ch;
            }
        }
        int sum=0;
        for(int i=0 ;i<n-1 ;i++){
            sum += abs(int(s[i] - s[i+1]));
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
