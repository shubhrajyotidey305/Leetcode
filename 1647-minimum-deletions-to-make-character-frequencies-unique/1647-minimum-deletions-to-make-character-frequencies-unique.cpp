class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26, 0);
        for(char c: s){
            f[c-'a']++;
        } 
        
        sort(f.begin(), f.end(), greater<int>());
        
        int count = 0;
        
        int j;
        int n = f.size();
        for(int i=0; i<n-1; i++)
        {
            if(!f[i]) break;
            j = i;
            while(j+1<n && f[j+1] == f[i]) {
                
                f[j+1]--;
                count++;
                j++;
            }
        }
        
        return count;
    }
};