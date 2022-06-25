class Solution {
public:
    bool checkPossibility(vector<int>& v) {
        int n = v.size();
        if(n == 1) return true;
        int count = 0;
        for (int i=1; i<n; i++){
            if (v[i]<v[i-1]){
                count++;
                if(i == 1 || v[i-2] <= v[i])
                    v[i-1] = v[i];    
                else 
                    v[i] = v[i-1];            }
            if (count>1) return false;
        }
        return true;
    }
};