class Solution {
public:
    bool check(vector<vector<int>>& t, int k, int n){
        int cnt = 0;
        for(auto &it:t){
            if(k==it[1]) cnt++;
        }
        return (cnt == n-1);
    }
    
    int findJudge(int n, vector<vector<int>>& t) {
        unordered_set<int> st;        
        
        for(auto &it:t){
            st.insert(it[0]);
        }
        
        for(int i=1; i<=n; i++){
            if(st.find(i)==st.end()){
                if(check(t, i, n)) return i;
            }
        }
        return -1;
    }
};