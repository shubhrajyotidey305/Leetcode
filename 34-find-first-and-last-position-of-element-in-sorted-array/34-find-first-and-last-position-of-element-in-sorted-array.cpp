class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        
        if(it1 == nums.end()){
            return{-1, -1};
        }
        
        int i1 = it1-nums.begin();
        int i2 = it2-nums.begin()-1;
        
        if(nums[i1] != target){
            return {-1, -1};
        }
        
        return{i1, i2};
    }
};