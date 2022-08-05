class Solution {
public:
    int dp[1001];
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, target, 0);
    }
    
    int solve(vector<int> &arr, int target, int sum) {
        if(sum == target) {
            return 1;
        }
        
        if(dp[sum] != -1) return dp[sum];
        
        int temp = 0;
        for(int i=0; i < arr.size(); i++) {
            if(sum + arr[i] <= target) {
                temp += solve(arr, target, sum+arr[i]);
            }
        }
        return dp[sum] = temp;
    }
};