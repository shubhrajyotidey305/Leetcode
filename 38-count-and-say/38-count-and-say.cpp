class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)    
            return "1";
        
        string s = "1";
        
        for(int i=2; i<=n; i++){
            int cnt = 1;            
            string temp = "";
            for(int i=1; i<s.length(); i++){
                if(s[i-1] == s[i])cnt++;
                else{
                    temp += to_string(cnt) + s[i-1];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + s[s.length()-1];
            s = temp;
            cout << s << endl;
        }
        return s;
    }
};