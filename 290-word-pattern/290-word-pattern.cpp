class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        int n = p.size();     
        string t;
        
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;
        
        int i = 0;
        
        while(getline(ss, t, ' ')){
            if(i == n or mp1[p[i]]!=mp2[t]) return false;            
            mp1[p[i]] = mp2[t] = i+1;
            i++;
        }
        
        return (i == n);
    }
};