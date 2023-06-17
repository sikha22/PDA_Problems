//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
         // Create a hash table to store the frequency of each element
        std::unordered_map<int, int> frequency;
        
          // Iterate through the array
        for (int i = 0; i < n; i++) {
            int num = a[i];
            
            // Increment the frequency of the current element
            frequency[num]++;
            
             // If the frequency of the element becomes equal to k, return it as the result
            if (frequency[num] == k) {
                return num;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
