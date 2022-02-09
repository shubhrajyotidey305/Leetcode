class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        multiset<int> st(nums.begin(), nums.end());
        set<pair<int, int>> s;       
        
        for(auto it:nums){  
            st.erase(st.find(it));
            if(!st.empty() and (st.find(k+it)!=st.end())){
                s.insert({it, it+k});
            }
            st.insert(it);            
        }        
        
        return s.size();
    }
};