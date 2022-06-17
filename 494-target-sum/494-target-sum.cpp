class Solution {
public:
    int cnt = 0;
    void solve(vector<int>& nums, int target, int n) {
        if(n == 0){
            if(target == 0) cnt++;
            return;
        }       
        
        solve(nums, target-nums[n-1], n-1);
        solve(nums, target+nums[n-1], n-1);                     
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums, target, nums.size());
        return cnt;
    }
};