class Solution {    
public:     
    vector<vector<int>> combinationSum(vector<int>& c, int t) {    
        vector<int> res;
        vector<vector<int>> ans;        
        dfs(0, c, t, res, ans);   
        
        for(auto &i:ans){
            sort(i.begin(), i.end());
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
    
    void dfs(int sum, vector<int>& c, int &t, vector<int> &res, vector<vector<int>> &ans){
        if(sum == t){
            ans.push_back(res);
            return;
        }
        
        if(sum > t){
            return;
        }
        
        for(auto it:c){
            res.push_back(it);
            dfs(sum+it, c, t, res, ans);
            res.pop_back();
        }
    }
};