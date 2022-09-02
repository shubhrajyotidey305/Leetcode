class Solution {
public:
    int lower(vector<int> &arr, int x) {
        int n = arr.size();
        int l = 0, r = n-1;
        int ans = n;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(arr[mid] <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int idx = lower(nums, target);
        if(idx == nums.size()) {
            if(target < nums[0]) {
                return 0;
            } else {
                return idx;
            }
        } else if(nums[idx] == target) {
            return idx;
        } else {
            return idx + 1;
        }
               
        
    }
};