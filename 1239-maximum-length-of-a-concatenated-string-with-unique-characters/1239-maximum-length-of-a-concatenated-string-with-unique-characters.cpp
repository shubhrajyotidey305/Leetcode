class Solution {
public:
    bool check(string &s) {
        vector<int> v(26, 0);
        
        for(auto it:s) {
            v[it-'a']++;
        }
        
        for(int i=0; i<26; i++) {
            if(v[i] > 1) {
                return false;
            }
        }
        return true;
    }
    
    int solve(int i, string &s, vector<string> &arr) {
        if(i == arr.size()) {
            if(check(s)) {
                return s.length();
            } else {
                return 0;
            }
        }
        
        s += arr[i];
        int op1 = solve(i+1, s, arr);
        
        int n = arr[i].size();
        while(n--) s.pop_back();
        
        int op2 = solve(i+1, s, arr);
        return max(op1, op2);        
    }
    
    int maxLength(vector<string>& arr) {
        string s = "";
        return solve(0, s, arr);
    }
};