//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<string> st;
            int i = 0, n = s.length();
            
            while(i<n){
                string temp="";
                if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                    temp.append(s, i, 1);
                    i++;
                }
                else{
                    while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && i<n){
                        temp.append(s, i, 1);
                        i++;
                    }
                }
                st.push(temp);
            }
            
            s="";
            for(int i=0; !st.empty(); i++){
                s += st.top();
                st.pop();
            }
            
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
