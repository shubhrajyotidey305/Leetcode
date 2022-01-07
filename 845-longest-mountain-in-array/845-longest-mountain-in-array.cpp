class Solution {
public:
    int longestMountain(vector<int>& a) {
        int res = 0;
        int n = a.size();
        
        for(int i=1; i<a.size(); i++){
            int cnt = 1;
            bool flag = false;
            
            int j = i;
            
            while(j<n and a[j]>a[j-1]){
                j++;
                cnt++;
            }
            
            while(i!=j and j<n and a[j]<a[j-1]){
                flag = true;
                j++;
                cnt++;                
            }
            
            if(i!=j and flag and cnt>2) res = max(res, cnt), j--;
            
            i = j;
            
        }
        
        return res;
    }
};