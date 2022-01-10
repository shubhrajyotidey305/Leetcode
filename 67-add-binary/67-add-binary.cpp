class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry  = 0;
        
        while(!a.empty() or !b.empty()){
            int sum = carry;
            int sa = 0, sb = 0;
            
            if(!a.empty()){
                sa = a.back() - '0';
                a.pop_back();
            }
            
            if(!b.empty()){
                sb = b.back() - '0';
                b.pop_back();
            }
            
            sum += (sa+sb);            
            carry = (sum>1)?1:0;            
            ans = to_string(sum%2) + ans;         
        }
        
        if(carry) ans = to_string(carry) + ans;
        return ans;
        
    }
};