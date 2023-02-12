//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
     private:
    long long res=-1;
    vector<int>* adj;
  public:
   void cycler(int node, vector<bool> &vis, vector<int> &par, vector<bool> &rec){
      vis[node]=true;
      rec[node]=true;
      for(auto nei: adj[node]){
          if(nei!=par[node] && vis[nei]==false){
              par[nei]=node;
              cycler(nei,vis,par,rec);
          }
          else if(rec[nei]==true){
              int c=node;
              long long sum=node;
              while(c!=nei){
                  c=par[c];
                  sum+=c;
              }
              res=max(res,sum);
          }
      }
      rec[node]=false;
  }

  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    adj=new vector<int>[N+1];
    for(int i=0;i<N;i++){
        if(Edge[i]==-1){
            continue;
        }
        adj[i].push_back(Edge[i]);
    }
    vector<bool> vis(N,false);
    vector<bool> rec(N,false);
    vector<int> par(N,-1);
    for(int i=0;i<N;i++){
        if(vis[i]==false){
            cycler(i,vis,par,rec);
        }
    }
    return res;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
