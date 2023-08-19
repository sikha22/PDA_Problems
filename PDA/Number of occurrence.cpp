//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
		int bs(int arr[], int l, int r, int x){
	    if(r < l)
	        return -1;
	        
	    int mid = (l + r)/2;
	    
	    if(arr[mid] == x)
	        return mid;
	        
	    if(arr[mid] > x)
	        return bs(arr, l, mid - 1, x);
	        
	    return bs(arr, mid + 1, r, x);
	}
	
	
	int count(int arr[], int n, int x) {
	    // code here
	     int index = bs(arr, 0, n - 1, x);
	    
	    if(index == -1)
	        return 0;
	        
	    
	    int count = 1;
	    
	    int left = index - 1;
	    int right = index + 1;
	    
	    while(left>=0 && arr[left]==x){
	        count++;
	        left--;
	    }
	    
	    while(right<n && arr[right]==x){
	        count++;
	        right++;
	    }
	    
	    return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
