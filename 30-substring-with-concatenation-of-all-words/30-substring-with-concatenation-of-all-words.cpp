class Solution {
public:   
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        int n=s.size(), m=words.size(), w=words[0].size();
        unordered_map<string, int> mp;
        for(auto &i: words) 
            mp[i]++;
        
        for(int i=0; i<w; i++){
            unordered_map<string, int> cnt;
            int k=0;
            for(int j=i; j<n; j+=w){
                if(j>=i+m*w){
                    string word = s.substr(j-m*w, w);
                    cnt[word]--;
                    if(cnt[word]<mp[word]) k--;
                }
                string word = s.substr(j, w);
                cnt[word]++;
                if(cnt[word]<=mp[word]) k++;
                if(k==m) v.push_back(j-(m-1)*w);
            }
        }
        return v;    
    }
};