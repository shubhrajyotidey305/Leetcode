class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for(auto &s : words) {
            mp[s]++;
        }
        
        int a = 0, b = 0;
        for(auto &it:mp) {
            string s = it.first;
            int f = it.second;
            
            if(s[0] == s[1]) {
                a = max(a, f%2);
                b += (f/2)*2;
            } else {
                string t = s;
                swap(t[0], t[1]);
                if(mp.count(t)) {
                    b += min(f, mp[t]);
                }
            }
        }
        return (a + b) * 2;
    }
};