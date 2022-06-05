class Solution {
private:
    set<vector<vector<int>>> st;
public:
    bool safe(int row, int col, vector<vector<int>> &v, int n){
        for(int i=0; i<col; i++){
            if(v[row][i])
                return false;
        }
        
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(v[i][j])
                return false;
        }
        
        for(int i=row, j=col; i<n && j>=0; i++, j--){
            if(v[i][j])
                return false;
        }
        
        return true;
    }
    
    void nqueen(vector<vector<int>> &v, int col, int n){
        if(col == n){
            st.insert(v);
            return;
        }    
        
        for(int i=0; i<n; i++){
            if(safe(i, col, v, n)){
                v[i][col] = 1;
                nqueen(v, col+1, n);
                v[i][col] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        st.clear();
        vector<vector<int>> v(n, vector<int>(n,0));
        nqueen(v, 0, n);
        return st.size();
    }
};