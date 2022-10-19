class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto &it:words) {
            mp[it]++;
        }
        
        auto comp = [&](pair<string, int> &a, pair<string, int> &b) {
          return a.second > b.second or (a.second == b.second and a.first < b.first);    
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        
        for(auto it:mp) {
            pq.push({it.first, it.second});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};