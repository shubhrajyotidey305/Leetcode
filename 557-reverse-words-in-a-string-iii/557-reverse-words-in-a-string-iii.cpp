class Solution {
public:
    string reverseWords(string s) {
        string ans = "", t;
        
        stringstream ss(s);
        
        while(getline(ss, t, ' ')){
            reverse(t.begin(), t.end());
            
            ans += t;
            ans += " ";
        }
        ans.pop_back();
        return ans;
        
    }
};