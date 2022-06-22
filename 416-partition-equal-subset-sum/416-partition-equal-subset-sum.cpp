class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++) total += nums[i];
            
        if(total & 1) return false;        
        total /= 2;
        
        int dp[n+1][total+1];    
        
        for(int i=0; i<=total; i++){
            dp[0][i] = 0;
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=total; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][total];
    }  
    
};