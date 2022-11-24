//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size(), ans = 0;
	    int dp[n] = {0}, dp_rev[n] = {0};
	    for(int i=0; i<n; i++){
	        dp[i] = 1;
	        for(int j=i-1; j>=0; j--){
	            if(nums[j] < nums[i])
	                dp[i] = max(dp[i], 1+dp[j]);
	        }
	    }
	    for(int i=n-1; i>=0; i--){
	        dp_rev[i] = 1;
	        for(int j=i+1; j<n; j++){
	            if(nums[j] < nums[i])
	                dp_rev[i] = max(dp_rev[i], 1+dp_rev[j]);
	        }
	    }
	    for(int i=0; i<n; i++){
	        ans = max(ans, dp[i]+dp_rev[i]-1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends