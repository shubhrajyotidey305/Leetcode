class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int t) {
        sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        });
            
        int ans = 0;
        int n = v.size();
        for(int i=0; i<n; i++){
            if(t - v[i][0] >= 0){
                ans += v[i][0]*v[i][1];
                t -= v[i][0];
            }       
            else {                
                ans += t*v[i][1];            
                break;
            }            
        }
        return ans;
    }
};