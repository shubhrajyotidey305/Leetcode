class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, i = 1, cnt = 0;
        
        while(i < s.size()) {
            if(s[i] != s[i-1]) {
                cnt += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
            i++;
        }
        return cnt += min(prev, curr);
    }
};