//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int>fact(n+1,1);
        for(int i=2;i<=n;i++){
            fact[i]=i*fact[i-1];
        }
        string res="";
        int flag=0;
        while(res.size()<n){
            int x=res.size();
            int a=(k-1)/(fact[n-x-1]);
            for(int b=0,c=0;b<n;b++){
                if((flag&(1<<b))){
                    continue;
                }
                if(c==a){
                    flag|=(1<<b);
                    res+=(b+1+'0');
                    break;
                }
                c++;
            }
            k=k-a*fact[n-1-x];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
