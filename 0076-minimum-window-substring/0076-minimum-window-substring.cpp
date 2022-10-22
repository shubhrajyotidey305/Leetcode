class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        
        for(auto i:t){
            mp[i]++;
        }
        
        int i=0, j=0;
        int cnt = mp.size();
        int n = s.length();
        int mini = INT_MAX, l = -1, r = -1;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    cnt--;
            }
            if(cnt==0){
                while(cnt == 0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1)
                            cnt++;
                    }
                    i++;
                }
                if(mini>j-i+2){
                    l = i-1;
                    r = j;
                    mini = j-i+2;
                }
            }
                
                
            j++;            
            
        }
        string res;
        if(l == -1)
            return "";
        res = s.substr(l, r-l+1);
        return res;   
    }
};