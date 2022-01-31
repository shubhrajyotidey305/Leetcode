class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int maxx = -1;
        int m = a.size(), n = a[0].size();
        
        for(int i=0;i<m;i++){
            int sum = 0;            
            for(int j=0;j<n;j++){
                sum += a[i][j];
            }
            maxx = max(maxx, sum);
        }
        return maxx;
        
    }
};