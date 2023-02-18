//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int i,j;
        i=j=0;
        int spellsUsed = 0;
        int maxLength=0;
        while(i<n){
            if(arr[i] == 'O') spellsUsed++;
            while(spellsUsed>m){
                if(arr[j]=='O') spellsUsed--;
                j++;
            }
            maxLength = max(maxLength, i-j+1);
            i++;
        }
        return maxLength;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
