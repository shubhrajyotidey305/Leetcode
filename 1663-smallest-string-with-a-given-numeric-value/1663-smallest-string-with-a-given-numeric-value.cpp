class Solution {
public:
    string getSmallestString(int n, int k) {
        unordered_map<int, char> mp;
        for(int i=1; i<=26; i++){
            mp[i] = (char) 'a' + i - 1;
        }
        
        string s (n, 'a');        
        k -= n;
        for(int i=n-1; i>=0; i--){
            if(k<=0) break;
            ++k;
            int idx = (k>26) ? 26 : k;            
            s[i] = mp[idx];            
            k -= idx;  
        }
        return s;
        
        
    }
};