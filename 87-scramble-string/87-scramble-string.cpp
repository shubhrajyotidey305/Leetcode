class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string A, string B) {
        mp.clear();
        int n = A.length(), m = B.length();
        if(n!=m) return false;
        if(n == 0 and m == 0) return true;
        return solve(A, B);
    }
    bool solve(const string &a, const string &b) {
        if(a == b) return true;
        if(a.length() <= 1) return false;

        string s = a + " " + b;
        if(mp.find(s) != mp.end()) return mp[s];

        int n = a.length();
        bool fl = false;
        for(int i=1; i<=n-1; i++) {
            bool c1 = solve(a.substr(0, i), b.substr(n-i, i)) and solve(a.substr(i, n-i), b.substr(0, n-i));
        bool c2 = solve(a.substr(0, i), b.substr(0, i)) and solve(a.substr(i, n-i), b.substr(i, n-i));

            if(c1 or c2) {
                fl = true;
                break;
            }
        }
        return mp[s] = fl;
    }
};