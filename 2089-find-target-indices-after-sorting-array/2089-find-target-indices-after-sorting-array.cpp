class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        
        if(it1 == nums.end()){
            return {};
        } 
        
        
        int i1 = it1 - nums.begin();
        int i2 = it2 - nums.begin();
        
        if(nums[i1]!=target){
            return {};
        }
        
        vector<int> v;
        for(int i=i1; i<i2; i++){
            v.push_back(i);
        }
        return v;
    }
};