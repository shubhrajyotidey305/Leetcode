class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        int n=nums.size();
        int count =0;
        vector<int>dp(1e5+10,0);
        
        for(auto &it:nums)
            dp[it[0]]=max(dp[it[0]] , it[1]);
        
        for(int i=1e5; i>=0 ;i--)
            dp[i]=max(dp[i],dp[i+1]);
        
        for(auto &it:nums){
            int val=dp[it[0]+1];
            if(val>it[1])
                count++;
        }
        return count;
    }
};