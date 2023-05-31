//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int> map;
        for(int i=0; i<n; i++)
            map[arr[i]]++;
        
        int min_freq = n+1;
        int max_no = -1;
        for(auto it:map){
            if(it.second < min_freq){
                min_freq = it.second;
                max_no = it.first;
            }
            else if(it.second == min_freq){
                max_no = max(max_no, it.first);
            }
        }
        
        return max_no;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
