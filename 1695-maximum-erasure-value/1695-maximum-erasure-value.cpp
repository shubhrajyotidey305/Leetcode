class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int current=0;
        int ans = INT_MIN;
        unordered_set<int> mp;
        for(int i=0,j=0;j<nums.size();j++){
            while(mp.find(nums[j])!=mp.end()){
                mp.erase(nums[i]);
                current -= nums[i];
                i++;
            }
            mp.insert(nums[j]);
            current += nums[j];
            ans = max(ans,current);
        }
        
        return ans;        
    }
};