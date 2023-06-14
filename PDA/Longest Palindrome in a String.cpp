//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        string longestPalin (string s) {
        int n=s.size();
        int bestLen=1; 
      
        int index=0; 
        
        
        for(int mid=0;mid<n;mid++){
            
            for(int x=1;mid-x>=0 && mid+x<n;x++){ 
                if(s[mid-x]!=s[mid+x]){
                    break;
                }
                
                int currLen=2*x+1; 
                if(currLen>bestLen){ 
                    bestLen=currLen;
                    index=mid-x;
                }
            }
        }
        
        for(int mid=0;mid<n-1;mid++){ 
            for(int x=1;mid-x+1>=0 && mid+x<n;x++){
                if(s[mid-x+1]!=s[mid+x]){
                    break;
                }
                int currLen=2*x; 
                if(currLen>bestLen){  
                    bestLen=currLen;
                    index=mid-x+1;
                }
            }
        }
        
        string ans=s.substr(index,bestLen); 
        return ans;
     }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
