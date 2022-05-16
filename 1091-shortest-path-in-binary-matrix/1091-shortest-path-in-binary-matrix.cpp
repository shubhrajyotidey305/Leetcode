class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1){
            return -1;
        }
        
        int n = grid.size();
        vector<vector<int>> dir = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
        
        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;
        
        while(!q.empty()){
            vector<int> point = q.front();
            q.pop();            
            
            int r = point[0];
            int c = point[1];

            if(r == n-1 and c == n-1){
                return point[2];
            }

            for(vector<int> v : dir){
                int rn = r + v[0];
                int cn = c + v[1];

                if(rn >= 0 and rn < n and cn >=0 and cn < n and grid[rn][cn] == 0){
                    q.push({rn, cn, point[2]+1});
                    grid[rn][cn] = 1;
                }
            }
            
        }
        return -1;
    }
};