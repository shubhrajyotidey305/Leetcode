// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	const int mod = 1e9+7;
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            if(arr[i-1]==0) dp[i][0] = 2*dp[i-1][0];
            else dp[i][0] = dp[i-1][0];
        }
        for(int i=1; i<=n; i++){
            for(int j=1;j<=sum; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod)%mod;
                }
                else{
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][sum];
	}
	
	int solve(vector<vector<int>> &dp, int arr[], int n, int sum){
	    if(n == 0){
	        if(sum == 0) return 1;
	        else return 0;
	    }
	    
	    if(dp[n][sum]!=-1) return dp[n][sum];
	    
	    if(arr[n-1]<=sum) return dp[n][sum] = (solve(dp, arr, n-1, sum-arr[n-1])%mod + solve(dp, arr, n-1, sum)%mod)%mod;
	    else return dp[n][sum] = solve(dp, arr, n-1, sum)%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends