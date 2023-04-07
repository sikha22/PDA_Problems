//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   bool isPalindrome(string str,int l,int r){
        while(l<r){
            if(str[l]!=str[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int addMinChar(string str){    
        //code here
          int n=str.length();
        char ch=str[0];
        int i=n-1;
        while(i>0){
            if(str[i]==ch){
                if(isPalindrome(str,0,i))break;
            }
            i--;
        }
        if(i!=0)return n-(i+1);
        else return n-1;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
