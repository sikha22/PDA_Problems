//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
 
    int nextHappy(int N){
        // code here
        N=N+1;
        int n=N;
        
        while(n!=1)   
        {
            
            while(n>4) 
            {
               int s=0 , d=n;
               while(d>0)
               {
                   s+=pow(d%10,2);
                   d/=10;
               }
               n=s;
            }
            
            
           if(n==1) return N;
           else
           {
               n=++N;
           }
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
