class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
        
        vector<int> v(256, 0);
        for(int i=0; i<n; i++){
            v[s[i]]++;
        }
        
        for(int i=0; i<n; i++){
            v[t[i]]--;
        }
        
        for(int i=0; i<256; i++){
            if(v[i] != 0) return false;
        }
        return true;
    }
};