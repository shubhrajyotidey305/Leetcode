// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int m, int v) 
	{ 
	    // Your code goes here
	    int dp[m+1][v+1];
	    for(int i=0; i<=v; i++) dp[0][i] = v+1;
	    for(int i=0; i<=m; i++) dp[i][0] = 0;
	    
	    for(int i=1; i<=m; i++){
	        for(int j=1; j<=v; j++){
	            if(coins[i-1]<=j){
	                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    return dp[m][v] > v ? -1 : dp[m][v];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends