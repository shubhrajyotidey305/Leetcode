class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        
        int l = 0, r = n-1;
        
        int area = 0;
        int ans = INT_MIN;
        
        while(l<r){
            area = min(h[l], h[r]) * (r-l);
            ans = max(ans, area);
            
            if(h[l]>h[r]){
                r--;
            }
            else
                l++;
        }
        return ans;
            
    }
};