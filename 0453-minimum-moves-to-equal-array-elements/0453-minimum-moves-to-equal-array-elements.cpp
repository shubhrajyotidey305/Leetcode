class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums) {
            sum += it;
        }
        
        int mini = *min_element(nums.begin(), nums.end());
        return sum - mini*(nums.size());
    }
};