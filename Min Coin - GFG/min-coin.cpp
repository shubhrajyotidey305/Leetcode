// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>&nums, int amount)
	{
	   // Code here
	   vector<int> dp(amount  + 1, INT_MAX);  
       dp[0] = 0; 
       for(int i = 1; i <= amount; i++)
       {
           for(int j = 0; j < nums.size(); j++)
           {
               if(((i - nums[j]) >= 0) && (dp[i - nums[j]] != INT_MAX))
               {
                 dp[i] = min(dp[i], dp[i - nums[j]] + 1); 
               }
           }
       }
       return (dp[amount] == INT_MAX)?-1 : dp[amount]; 
       
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends