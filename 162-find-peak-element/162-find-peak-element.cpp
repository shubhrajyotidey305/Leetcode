class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1, nums.size());
    }
    
    int solve(vector<int> &nums, int low, int high, int n) {
        int mid = low + (high - low) / 2;
        if((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == n - 1 || nums[mid + 1] <= nums[mid]))
            return mid;
        else if(mid > 0 && nums[mid - 1] > nums[mid]) return solve(nums, low, mid-1, n);
        else return solve(nums, mid+1, high, n);
    }
};