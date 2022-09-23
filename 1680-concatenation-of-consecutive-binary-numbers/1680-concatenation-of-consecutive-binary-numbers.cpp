class Solution {
public:
    const int mod = 1e9+7;
    int ans = 0, k = 1;
    void solve(int n) {
        while(n) {
            int a = n%2;
            ans = (ans + a*k) % mod;
            k = (k*2) % mod;
            n /= 2;
        }
    }
    
    int concatenatedBinary(int n) {
        for(int i=n; i>=1; i--) {
            solve(i);
        }
        return ans;
    }
};