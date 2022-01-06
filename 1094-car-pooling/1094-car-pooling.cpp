class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int cap) {
        vector<int> v(10001, 0);
        
        int n = t.size();
        for(int i=0; i<n; i++){
            v[t[i][1]] += t[i][0];
            v[t[i][2]] -= t[i][0];
        }
        
        int sum = 0;
        for(int i=0; i<10001; i++){
            sum += v[i];
            if(sum > cap){
                return 0;
            }
        }
        return 1;
        
    }
};