class Solution {
public:
    bool validPalindrome(string s) {
        string t (s.rbegin(), s.rend());
        if(s == t){
            return true;
        }
        
        int n = s.size();
        int idx = -1;
        for(int i=0; i<n; i++){
            if(s[i]!=t[i]){
                idx = i;
                break;
            }
        }
        
        s.replace(idx, 1, "");        
        if(s == string(s.rbegin(), s.rend())) return true;
        
        t.replace(idx, 1, "");        
        if(t == string(t.rbegin(), t.rend())) return true;
        
        return  false;
    }
};