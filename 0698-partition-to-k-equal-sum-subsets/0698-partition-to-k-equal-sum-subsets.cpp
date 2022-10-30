class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it:nums) sum += it;
        
        if(sum % k) {
            return false;
        }
        
        sum /= k;
        vector<bool> vis(nums.size(), false);
        sort(begin(nums),end(nums),greater<int>());
        return solve(0, 0, sum, k, vis, nums);
    }
    
    bool solve(int i, int curr, int sum, int k, vector<bool> &vis, vector<int> &nums) {
        if(k == 1) {
            return true;
        }
        
        if(i >= nums.size()) {
            return false;
        }
        
        if(curr == sum) {
            return solve(0, 0, sum, k-1, vis, nums);
        }
        
        
        for(int j=i; j<nums.size(); j++) {
            if(vis[j] or curr + nums[j] > sum) continue;
            vis[j] = true;
            
            if(solve(j+1, curr + nums[j], sum, k, vis, nums)) {
                return true;
            }
            
            vis[j] = false;
        }
        return false;
    }
};