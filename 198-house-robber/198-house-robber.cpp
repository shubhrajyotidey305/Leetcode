class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev2 = 0, prev = 0, curr;
        
        for(int i=1; i<=n; i++) {
            int op1 = nums[i-1];
            if(i > 1) {
                op1 += prev2;
            }
            
            int op2 = prev;
            
            curr = max(op1, op2);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};