// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    #define ll long long
    #define mod 1000000007
    int kvowelwords(int n, int k){
        vector<vector<ll>>dp(n+1,vector<ll>(k+1,1));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0)dp[i][j]=21*dp[i-1][k]%mod;
                else{
                    dp[i][j]=(5*dp[i-1][j-1]%mod+21*dp[i-1][k]%mod)%mod;
                }
            }
        }
        return dp[n][k];
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends