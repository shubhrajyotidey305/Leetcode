// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++) sum += arr[i];
	    
	    bool dp[n+1][sum/2+1];
	    for(int i=0; i<=sum/2; i++) dp[0][i] = false;
	    for(int i=0; i<=n; i++) dp[i][0] = true;
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum/2; j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
	            }
	            else {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    int s = 0;
	    for(int i=0; i<=sum/2; i++){
	        if(dp[n][i]) s = i;
	    }
	    return sum - s - s;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends