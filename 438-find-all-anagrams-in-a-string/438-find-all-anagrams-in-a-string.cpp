class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int visp[256] = {0};
        int viss[256] = {0};
        int k = p.size();
        int n = s.size();
        
        if(k>n) return {};
        
        for(auto &it:p){
            visp[it]++;
        }
        
        for(int i=0; i<k; i++){
            viss[s[i]]++;
        }
        
        for(int i=k; i<n; i++){
            if(check(viss, visp)){
                ans.push_back(i-k);
            }
            
            --viss[s[i-k]];
            ++viss[s[i]];          
            
        }
        
        if(check(viss, visp)){
            ans.push_back(n-k);
        }
        
        return ans;
    }
    
    bool check(int viss[], int visp[]){
        for(int i=0; i<256; i++){
            if(visp[i]!=viss[i]) return false;
        }
        return true;
    }
};