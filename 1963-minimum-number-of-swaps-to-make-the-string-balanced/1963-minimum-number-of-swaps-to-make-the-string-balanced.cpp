class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int a = 0;
        int maxx = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ']'){
                a++;
            }else{
                a--;
            }
            maxx = max(a,maxx);
        }
        return (1 + maxx)>>1;
    }
};