class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        
        map<char, int> mp;
        
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        
        int maxi = -1, cut = -1;
        for(int i=0; i<n; i++){
            maxi = max(maxi, mp[s[i]]);
            
            if(i == maxi){
                ans.push_back(maxi-cut);
                cut = maxi;
            }
        }
        return ans;
        
    }
};