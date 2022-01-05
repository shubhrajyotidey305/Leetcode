class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int ans = INT_MAX;
        int sum = 0;
        int start = 0, end = 0;
        int n = a.size();
        
        while(end<n){
            while(sum<t and end<n){
                sum += a[end++];
            }
            while(sum>=t and start<n){
                if(end-start<ans){
                    ans = end-start;
                }
                sum -=a[start++];
            }
        }
        return ans == INT_MAX?0:ans;
        
        
    }
};