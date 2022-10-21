class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<vector<int>> v;
        for(int i=0; i<nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        
        for(int i=1; i<v.size(); i++) {
            if(v[i][0] == v[i-1][0]) {
                if(abs(v[i][1] - v[i-1][1]) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};