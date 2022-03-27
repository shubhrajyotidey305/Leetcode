class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1) cnt++;
            }
            v.push_back({cnt, i});
        }
        
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
    
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first < b.first){
            return true;
        }
        else if(a.first == b.first){
            return (a.second < b.second);
        }
        else return false;
    }
};