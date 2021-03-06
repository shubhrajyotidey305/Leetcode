class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        
        for(auto &it : nums){
            if(it == 0) cnt0++;
            else if(it == 1) cnt1++;
            else cnt2++;
        }
        
        int i = 0;
        while(cnt0--) nums[i++] = 0;
        while(cnt1--) nums[i++] = 1;
        while(cnt2--) nums[i++] = 2;
    }
};