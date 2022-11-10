#include <bits/stdc++.h>
using namespace std; 
int sumOfMaxMin(int arr[], int n){
	// Write your code here.
    int m = INT_MIN;
    int a = INT_MAX;
    for(int i=0;i<n;i++){
        m=max(arr[i],m);
        a=min(arr[i],a);
    }
    return m + a;
    
}

int main(){
    int r;
    cout<<"Enter the size of an array:";
    cin>>r;
    cout<<"Enter the element in the array :";
    int arr[r];
     for(int i=0;i<r;i++){
        cin>>arr[i];
    }
    
    int res = sumOfMaxMin(arr,r);
    // return sumOfMaxMin(int arr[],int n);
    cout<<"sum of max and min is :"<<res<<endl;


}