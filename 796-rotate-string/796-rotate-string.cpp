class Solution {
public:
    bool rotateString(string s, string g) {
        g += g;
        if(g.size() == s.size()) return false;
        return g.find(s) == string::npos ? false : true;
        
    }
};