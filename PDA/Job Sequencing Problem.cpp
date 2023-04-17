//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool mycmp(struct Job a,struct Job b)
    {
        if(a.profit > b.profit)
            return true;
        else if(a.profit == b.profit)
            return a.dead > b.dead;
        else
            return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,mycmp);
        vector <int> ans;
        int c = 0;
        int maxdead = INT_MIN;
        int profit = 0;
        for(int i = 0;i < n;i++)
        {
            maxdead = max(maxdead,arr[i].dead);
        }
        vector <bool> check (maxdead + 1,false); 
        for(int i = 0;i < n;i++)
        {
            if(check[arr[i].dead] == false)
            {
                check[arr[i].dead] = true;
                profit+=arr[i].profit;
                c++;
            }
            else{
                int temp = arr[i].dead - 1;
                while(temp > 0 and check[temp] == true)
                {
                    temp--;
                }
                if(temp > 0 and check[temp] == false)
                {
                    check[temp] = true;
                    profit+=arr[i].profit;
                    c++;
                    
                }
            }
        }
        ans.push_back(c);
        ans.push_back(profit);
        return ans;
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
