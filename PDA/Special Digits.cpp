//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    #define mod (int)(1e9+7)
    long long Fact[100001];
    
    int binexp(int n, int x){
        int ans=1;
        while(x){
            if(x&1) ans= (ans*1LL*n)%mod;
            n=(n*1LL*n)%mod;
            x>>=1;
        }
        return ans;
    }
    
    int nCr(int N, int i){
        int numerator=Fact[N];
        int denominator= (Fact[i]*1LL*Fact[N-i])%mod;
        
        return (numerator*1ll*binexp(denominator,mod-2))%mod;
    }
    // n!/ (i!* (n-1)!)
    //in case of large valuu we take 
    // numerator%mod * dunomenatoe^mod-2 %mod
    
    bool is_best(int sum, int C, int D){
        while(sum>0){
            int rem=sum%10;
            if(rem!=C && rem!=D){
                return false;
            }
            sum=sum/10;
        }
        return true;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        Fact[0]=1;
        for(int i=1;i<100001;i++){
            Fact[i]=(i*Fact[i-1])%mod;
        }
        
        long long ans=0;
        for(int i=0;i<=N;i++){
            //i-> number of A's
            // n-1 number of B's
            int sum=i*A+ (N-i)*B;
            if(is_best(sum,C,D)){
                ans= (ans+ nCr(N,i)%mod)%mod;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
