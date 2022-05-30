class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c:s){
            if(c >= 'A' and c <= 'Z' or c >= 'a' and c <= 'z' or c >= '0' and c <= '9'){
                str += tolower(c);
            }
        }       
        return str == string(str.rbegin(), str.rend());
    }
};