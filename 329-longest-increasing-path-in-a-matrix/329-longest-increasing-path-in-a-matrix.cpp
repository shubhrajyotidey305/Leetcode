class Solution {
public:
    int longestPath[201][201];
    int maxVal = 0;
    vector<int> x = {0, -1,  0, 1};
    vector<int> y = {1,  0, -1, 0};    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(m == 1 && n == 1){
            return 1;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                longestPath[i][j] = -1;
            }
        }
        
        for(int r=0;r<m;r++){
            for(int s=0;s<n;s++){
                if(longestPath[r][s] == -1){
                    DFS(r,s,m,n,matrix);
                }
            }
        }
        
        return maxVal;
    }
    
    int DFS(int r, int c, int row, int col, vector<vector<int>>& matrix){
        
        if(!isPath(r,c,row,col,matrix)){
            longestPath[r][c] = 1;
            return 1;
        }
        
        if(longestPath[r][c] != -1){
            return longestPath[r][c];
        }
            
        
        for(int i=0;i<4;i++) {
            if(isWithIn(r+x[i], c+y[i], row, col) && matrix[r + x[i]][c + y[i]] > matrix[r][c]){
                longestPath[r][c] = max(longestPath[r][c], DFS(r + x[i], c + y[i], row, col, matrix) + 1);
                maxVal = max(maxVal, longestPath[r][c]);
            } 
        }
        
        return longestPath[r][c];
    }
    
    bool isPath(int m_x, int n_x, int m, int n, vector<vector<int>>& matrix){
        
        for(int i=0;i<4;i++){
            if(isWithIn(m_x + x[i], n_x + y[i], m, n) && matrix[m_x + x[i]][n_x + y[i]] > matrix[m_x][n_x]){
                return true;
            }
        }
        
        return false;
    }
    
    bool isWithIn(int m_x, int n_x, int m, int n){
        return m_x < m && m_x >=0 && n_x <n && n_x >= 0;
    }
};