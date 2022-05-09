class Solution {
private:
    vector < string > nos = {"" , "" , "abc","def" ,"ghi","jkl","mno","pqrs","tuv","wxyz" }; 
    vector < string > ans;
public:
    void solve(string s , int b, int n , string  op){
         if(b == n) {
             ans.push_back(op);
             return ;
        }

        for(char c : nos[s[b]-'0']){
            op = op + c;
            solve(s , b+1 , n , op);
            op.pop_back();
        }
     }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
    
        if(n == 0) return {};

        solve(digits , 0 , n , "");


        return ans;
    }
};