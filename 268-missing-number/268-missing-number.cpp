class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = 0;
        for(auto i : nums)
            xr = xr ^ i;
        
        for(int i=0; i<=nums.size(); i++){
            xr = xr ^ i;
        }
        return xr;
    }
};