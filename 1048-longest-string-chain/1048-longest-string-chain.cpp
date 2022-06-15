class Solution {
public:
    int longestStrChain(vector<string>& w) {
        unordered_map<string,int>mp;
        sort(w.begin(),w.end(), [&](string &a, string &b){
            return a.size() < b.size();
        });
        int ans=0;
        for(int i=0;i<w.size();i++){
            string str=w[i];
            for(int j=0;j<str.length();j++){
                string cp=str;
                cp.erase(cp.begin()+j);
                int temp=1;
                if(mp.find(cp)!=mp.end())temp+=mp[cp];
                mp[str]=max(mp[str],temp);
            }
            ans=max(ans,mp[str]);
        }
        return ans;
    }
};