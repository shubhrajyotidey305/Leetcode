class Solution {
public:
    bool detectCapitalUse(string w) {
        int cnt = 0;
        for(auto &it:w){
            if(it>='A' and it<='Z') cnt++;
        }
        
        if(cnt == w.size()) return true;
        if(cnt == 0) return true;
        if(cnt == 1 and (w[0]>='A' and w[0]<='Z')) return true;
        return false;
    }
};