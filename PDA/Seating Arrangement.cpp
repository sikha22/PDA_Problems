//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
            for(int i = 0; i < m; ++i){
            // if n is exhausted
            if(n == 0) break;
            
            // for first seat
            if(i == 0 && seats[i] == 0 && seats[i+1] == 0){
                seats[i] = 1;
                n -= 1;
            }
            // for last seat
            else if(i == m-1 && seats[i] == 0 && seats[i-1] == 0){
                seats[i] = 1;
                n -= 1;
            }
            // for middle seats
            else{
                if(seats[i] == 0 && seats[i-1] == 0 && seats[i+1] == 0){
                    seats[i] = 1;
                    n -= 1;
                }
            }
        }
        
        return n == 0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends
