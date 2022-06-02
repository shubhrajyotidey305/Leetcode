class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int, int>> v;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    v.push_back({i, j});
                }
            }
        }
        
        for(auto &it:v){
            int row = it.first;
            int col = it.second;
            
            for(int i=0; i<m; i++){
                mat[row][i] = 0;
            }
            
            for(int i=0; i<n; i++){
                mat[i][col] = 0;
            }
        }
    }
};