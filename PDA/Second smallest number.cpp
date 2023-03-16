//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
         if(S >= 9 * D) return "-1";
        
        int smallest = 0;
        for(int i = 0; i < D; i++) {
            int maxS = 9 * (D - 1 - i);
            int val = 0;
            if(i == 0) val = 1;
            if(S - maxS > 0) {
                val = S - maxS;
            }
            
            S -= val;
            smallest = smallest * 10 + val;
        }
        
        // cout << smallest << endl;
        
        int secondSmallest = 0;
        int cnt = 0;
        while(1) {
            if(cnt >= D - 1) break;
            
            int ld = smallest % 10;
            smallest /= 10;
            int sld = smallest % 10;
            
            if(sld != 9) {
                sld++;
                ld--;
                smallest /= 10;
                secondSmallest = smallest * pow(10, cnt + 2) + 
                                 sld * pow(10, cnt + 1) + 
                                 ld * pow(10, cnt) + 
                                 secondSmallest;
                break;
                
            } else {
                secondSmallest = ld * pow(10, cnt) + secondSmallest;
                cnt++;
            }
        }
        
        return to_string(secondSmallest);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
