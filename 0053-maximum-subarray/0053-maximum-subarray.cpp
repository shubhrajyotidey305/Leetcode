class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, curr = 0;
        for(auto it:nums) {
            curr += it;
            ans = max(curr, ans);
            
            if(curr < 0) {
                curr = 0;
            }
        }
        return ans;
    }
};