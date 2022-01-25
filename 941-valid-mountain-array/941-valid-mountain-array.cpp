class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int l = 1, r = 0;        
        int n = a.size();
        
        if(n<3) return false;
        
        int i = 1;        
        while(i<n and a[i]>a[i-1]){ 
            l++;
            i++;
         }
        
        int j = n-2;
        while(j>=0 and a[j]>a[j+1]){ 
            r++;
            j--;
        }
        
        // cout << l << " " << r;
        return (r!=0 and l!=1 and (l+r) == n);
    }
};