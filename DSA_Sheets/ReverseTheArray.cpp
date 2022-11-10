#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int> &arr , int m,int x)
{
	// Write your code here.
    int n =arr.size();
    int a = n-1;
    for(int i= x+1;i<=a;i++){
        swap(arr[i],arr[a]);
        a--;
    }
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
    
}
// void printvec(vector<int> &arr , int m){
//     for(int i=0;i<m;i++){
//         cout<<arr[i];
//     }
// }
int main(){
    int n;
    cout<<"Enter no. : ";
    cin>>n;
    int x;
    cout<<"Enter the index after u want to reverse "; 
    cin>>x;
    vector<int> v;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<n;j++){
        v.push_back(arr[j]);
    }
    
        
    
    reverseArray(v, n,x);
    // printvec(v,n);

    return 0;


}
