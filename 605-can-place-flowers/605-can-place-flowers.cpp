class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int len = f.size();
        int cnt = 0;     
        
        if(len == 1){
            if(f[0] == 0 and n<=1) return true;
            if(f[0] == 1 and n==0) return true;
            return false;
        }
        
        for(int i=0; i<len; i++){
            if(cnt == n) break;
            if(i == 0){
                if(f[i] == 0 and f[i+1] != 1){
                    cnt++;
                    f[i] = 1;
                }
            }
            else if(i==len-1){
                if(f[i] == 0 and f[i-1]!=1){
                    cnt++;
                    f[i]=1;
                }
            }
            else{
                if (f[i] == 0){
                    if(f[i-1]!=1 and f[i+1]!=1){ 
                        cnt++;
                        f[i] = 1;
                    }
                }
            }
        }
        
        return (cnt == n);
    }
};