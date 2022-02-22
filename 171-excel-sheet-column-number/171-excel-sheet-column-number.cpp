class Solution {
public:
    int titleToNumber(string s) {
        long long ans = 0, i = 1;
        while(!s.empty()){
            char c = s.back();
            s.pop_back();
            
            ans += (i*(getValue(c)));
            i*=26;            
        }
        return ans;
        
    }
    
    int getValue(char c){
        return (c-'A'+1);
    }
};