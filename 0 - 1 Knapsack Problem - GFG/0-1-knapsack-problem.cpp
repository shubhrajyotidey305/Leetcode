// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1002][1002];
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        // Your code here
        memset(dp, -1, sizeof(dp));
        return solve(w, wt, val, n);
        
    }
    
    int solve(int w, int wt[], int val[], int n){
        if(n == 0 or w == 0) return 0;
        
        if(dp[n][w] != -1) return dp[n][w];
       
        if(wt[n-1]<=w){
            return dp[n][w] = max(val[n-1] + solve(w-wt[n-1], wt, val, n-1), solve(w, wt, val, n-1));
        }
        else return dp[n][w] = solve(w, wt, val, n-1);
    }
    
    
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends