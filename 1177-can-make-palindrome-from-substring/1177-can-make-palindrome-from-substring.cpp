class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map<int, vector<int>> mp;
        vector<int> f(26, 0);
        mp[-1] = f;
        
        for(int i=0; i<n; i++) {
            f[s[i]-'a']++;
            mp[i] = f;
        }
        vector<bool> ans(queries.size());
        for(int i=0; i<queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            
            vector<int> f(26, 0);
            int odd = 0;
            for(int j=0; j<26; j++) {
                f[j] = mp[r][j] - mp[l-1][j];
                if(f[j] % 2) odd++;
            }
            
            if(odd / 2 > k) {
                ans[i] = false;
            } else {
                ans[i] = true;
            }            
        }
        return ans;
    }
};