class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int sum = 0;
        unordered_map<int, vector<int>> mp;
        
        for(int i=0; i<n; i++){
            if(nums[i] == 0) nums[i] = -1;
            sum += nums[i];
            if(sum == 0) len = i+1;
            mp[sum].push_back(i);
        }
        
        
        
        
        for(auto it:mp){
            auto v = it.second;
            len = max(len, *v.rbegin() - *v.begin());
        }
        return len;
        
        
    }
};