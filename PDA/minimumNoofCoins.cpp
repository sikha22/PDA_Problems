#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> minPartition(int N){
        vector<int> money;
        int a[10]={2000,500,200,100,50,20,10,5,2,1};
        for(int i=0 ;i<10;i++){
            int n=N/a[i];
            for(int j=0;j<n;j++){
                money.push_back(a[i]);
            }
            N%=a[i];
        }
        return money;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
        cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}