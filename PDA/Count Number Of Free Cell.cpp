//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      int r[n]={0},c[n]={0};

      long long count=n*n;

      int r1=0,c1=0;

      vector<long long int> res;

      for(int i=0;i<k;i++)

      {

          if(r[arr[i][0]-1]==0 && c[arr[i][1]-1]==0)

          {

              count=count-2*n+r1+c1+1;

              r1++;

              c1++;

              r[arr[i][0]-1]=1;

              c[arr[i][1]-1]=1;

          }

          else if(r[arr[i][0]-1]==0 && c[arr[i][1]-1]==1)

          {

              count=count-n+c1;

              r[arr[i][0]-1]=1;

              r1++;

          }

          else if(r[arr[i][0]-1]==1 && c[arr[i][1]-1]==0)

          {

              count=count-n+r1;

              c[arr[i][1]-1]=1;

              c1++;

          }

          res.push_back(count);

      }

      return res;


  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
