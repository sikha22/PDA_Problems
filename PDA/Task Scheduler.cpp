//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
           unordered_map <char,int>m;
        int maxFrequency=0,elements=1;
        //initially we will assume only 1 element will have maximum frequency
        for(int i=0;i<N;i++){
            if(!m[tasks[i]]){
                m[tasks[i]]=1;
            }
            else{
                m[tasks[i]]++;
            }
            if(maxFrequency==m[tasks[i]]) elements++;
            else if(maxFrequency<m[tasks[i]]) elements=1;
            maxFrequency=max(maxFrequency,m[tasks[i]]);
        }
        int ans=((maxFrequency-1)*(K+1))+elements;
        return max(ans,N);
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
