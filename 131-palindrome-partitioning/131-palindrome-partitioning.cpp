class Solution {
public:
     bool isSubstringPal(int start, int end) {
        while (start < end) {
            if (str[start] != str[end])
                return false;
            start++; end--;
        }
        return true;
    }
    
    
    void backtrack(int start, vector<string> curr) {
        if (start >= str.size())
            res.push_back(curr);
            
        int end = start;
        while (end < str.size()) {
            if (isSubstringPal(start, end)) {
                curr.push_back(str.substr(start, end-start+1));
                backtrack(end+1, curr);
                curr.pop_back();
            }
            end++;
        }
    }
    
    vector<vector<string>> partition(string s) {
        str = s;
        backtrack(0, {});
        return res;
    }
    
private:
    vector<vector<string>> res;
    string str;
};