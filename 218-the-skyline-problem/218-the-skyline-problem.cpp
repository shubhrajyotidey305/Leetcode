class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& a) {
        int n = a.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({a[i][0], -a[i][2]});
            v.push_back({a[i][1], a[i][2]});
        }
        
        sort(v.begin(), v.end());
                
        vector<vector<int>> ans;
        multiset<int> st;
        st.insert(0);
        int curr = 0;
        
        for(int i=0; i<v.size(); i++) {
            int point = v[i].first;
            int height = v[i].second;
            
            if(height < 0) {
                st.insert(-height);
            } else {
                auto it = st.find(height);
                st.erase(it);
            }           
            
            
            if(curr != *st.rbegin()) {
                vector<int> temp;
                temp.push_back(point);
                temp.push_back(*st.rbegin());
                
                ans.push_back(temp);
                curr = *st.rbegin();
            }
        }
        return ans;        
    }
};