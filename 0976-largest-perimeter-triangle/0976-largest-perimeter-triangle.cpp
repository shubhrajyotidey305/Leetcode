class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        int ans = 0;
        
        for(int i=0; i<=nums.size()-3; i++) {
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if(a + b > c and b + c > a and a + c > b) {
                ans = max(ans, a + b + c);
            } 
        }
        return ans;   
    }
};