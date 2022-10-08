class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, ans = 0;
        
        for(int i=0; i<n-2; i++) {
            int l = i+1;
            int r = n-1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];                 
                if(abs(sum - target) < diff) {
                    ans = sum;
                    diff = abs(sum - target);
                }
                
                if(sum <= target) l++;
                else r--;                
            }     
            
        }
        return ans;
    }
};