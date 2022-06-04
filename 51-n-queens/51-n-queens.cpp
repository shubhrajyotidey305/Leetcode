class Solution {
public:
    bool safe(int row, int col, int n, vector<string> &visited){
        for(int i=0; i<col; i++){
            if(visited[row][i] == 'Q')
                return false;
        }
        
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(visited[i][j] == 'Q')
                return false;
        }
        
        for(int i=row, j=col; i<n && j>=0; i++, j--){
            if(visited[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
    void nqueen(vector<vector<string>> &ans, vector<string> &visited, int col, int n ){
        if(col == n){
            ans.push_back(visited);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(safe(i, col, n, visited)){
                visited[i][col] = 'Q';
                nqueen(ans, visited, col+1, n);
                visited[i][col] = '.';
            }
        }        
    }    
    
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0; i<n; i++)
            s.push_back('.');
        
        vector<string> visited;
        
        for(int i=0; i<n; i++)
            visited.push_back(s);
        
        vector<vector<string>> ans;
        
        nqueen(ans, visited, 0, n);
        
        vector<vector<string>> res(ans.begin(), ans.end());
        
        return res;
        
    }
};