//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	        int state=0;
    for(int i=0;i<s.length();i++)
    {
        if(state==0)
        {
            if(s[i]=='0')
            state=0;
            else
            state=1;
        }
        else
        if(state==1)
        {
            if(s[i]=='0')
            state=2;
            else
            state=0;
        }
        else
        {
            if(s[i]=='0')
            state=1;
            else
            state=2;
        }
    }
    if(state==0)
    return 1;
    return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends
