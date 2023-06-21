//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int a, vector<int> &bills) {
        // code here
            map<int , int> m;
        vector<int > temp;
        for(int i=0;i< bills.size();i++)
        {
            if(bills[i]==5)
            m[5]++;
            else if(bills[i]==10)
            {
                if(m[5]>0)
                {
                 m[10]++;
                 m[5]--;
                }
                else return false;
            }
            else if(bills[i]==20)
            {
                if(m[10]>0 && m[5]>0)
                {
                    m[10]--;
                    m[5]--;
                    m[20]++;
                }
                else if(m[5]>2)
                {
                    m[5]-=3;
                    m[20]++;
                }
                else return false;
            }
            
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
