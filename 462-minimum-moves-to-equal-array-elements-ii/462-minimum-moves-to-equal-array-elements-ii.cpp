class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n%2){
            return solve(nums, n/2, n);
        }
        else {
            return max(solve(nums, n/2-1, n), solve(nums, n/2, n));
        }
        
    }
    
    int solve(vector<int> &nums, int idx, int n){
        int sum = 0, x = nums[idx];
        for(int i=0; i<n; i++){
            sum += abs(nums[i] - x);
        }       
        return sum;
    }
};