//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Program for zig-zag conversion of array
     void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void zigZag(int arr[], int n) {
        // code here
          bool flag = true;  // flag to indicate whether the current element should be smaller or larger
        for (int i = 0; i < n - 1; i++) {
            if (flag) {
                // If the current element should be smaller, but it is larger, swap it with the next element
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            } else {
                // If the current element should be larger, but it is smaller, swap it with the next element
                if (arr[i] < arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            }
            flag = !flag;  // Toggle the flag for the next iteration
        }
    }
};

//{ Driver Code Starts.

bool isZigzag(int arr[], int n){
    int f=1;
    
    for(int i=1; i<n; i++){
        if(f){
            if(arr[i-1]>arr[i]) return 0;
        }
        else{
            if(arr[i-1]<arr[i]) return 0;
        }
        f=f^1;
    }
    
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        bool check=1;
        check=isZigzag(arr,n);
        
        if(check) cout<<"1\n";
        else cout<<"0\n";
        
    }
    return 0;
}

// } Driver Code Ends
