class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            int temp = 0;
            
            unordered_map<double, int> mp;
            
            for(int j=0; j<n; j++) {
                if(i != j) {
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    
                    double nu = y2 - y1;
                    double de = x2 - x1;
                    
                    if(de == 0) {
                        mp[INT_MAX]++;
                        
                        temp = max(temp, mp[INT_MAX]);
                    } else {
                        double slop = nu / de;
                        mp[slop]++;
                        
                        temp = max(temp, mp[slop]);
                    }
                }
            }
            ans = max(ans, temp + 1);            
        }
        return ans;
    }
};