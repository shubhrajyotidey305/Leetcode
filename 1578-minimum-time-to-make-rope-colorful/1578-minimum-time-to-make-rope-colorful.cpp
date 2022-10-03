class Solution {
public:
    int minCost(string col, vector<int>& arr) {
        int ans = 0;
        int curr = arr[0];
        int maxi = arr[0];
        int n = col.size();
        
        for(int i=1; i<n; i++) {
            if(col[i] != col[i-1]) {
                ans += (curr - maxi);
                maxi = 0; 
                curr = 0;
            }  
            
            curr += arr[i];
            maxi = max(maxi, arr[i]);
        }
        ans += (curr - maxi);
        return ans;
    }   
    
};