class Solution {
public:
    int solve(int pos, int n, int mask) {
        if(pos > n) {
            return 1;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(mask & (1 << i) and (pos % (i+1) == 0 or (i+1) % pos == 0)) {   
                ans += solve(pos+1, n,  mask ^ (1 << i));                     
            }
        }
        return ans;
    }
    
    int countArrangement(int n) {
        return solve(1, n, (1<<n) - 1);    
    }
};